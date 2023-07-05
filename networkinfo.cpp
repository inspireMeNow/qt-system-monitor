#include "networkinfo.h"
Net *set_args(std::string ifname,
              std::string iftype,
              std::string mac,
              std::string ip,
              std::string mask,
              std::string broadcast,
              std::string gateway,
              std::string upload_speed,
              std::string download_speed,
              std::string upload_bytes,
              std::string download_bytes)
{
    Net *n = new Net;
    n->ifname = ifname;
    n->iftype = iftype;
    n->mac = mac;
    n->ip = ip;
    n->mask = mask;
    n->broadcast = broadcast;
    n->gateway = gateway;
    n->upload_speed = upload_speed;
    n->download_speed = download_speed;
    n->upload_bytes = upload_bytes;
    n->download_bytes = download_bytes;
    return n;
}
std::vector<Net> get_net()
{
    std::vector<Net> v;
    struct ifaddrs *ifaddr, *ifa;
    if (getifaddrs(&ifaddr) == -1)
    {
        std::cerr << "getifaddrs() failed: " << std::strerror(errno) << std::endl;
        return std::vector<Net>();
    }

    // 遍历网络接口列表
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next)
    {
        if (ifa->ifa_addr == NULL)
        {
            continue;
        }

        // 获取网络接口信息
        struct ifreq ifr;
        std::memset(&ifr, 0, sizeof(ifr));
        std::strncpy(ifr.ifr_name, ifa->ifa_name, IFNAMSIZ - 1);
        int fd = socket(AF_INET, SOCK_DGRAM, 0);
        if (fd == -1)
        {
            std::cerr << "socket() failed: " << std::strerror(errno) << std::endl;
            continue;
        }
        if (ioctl(fd, SIOCGIFHWADDR, &ifr) == -1)
        {
            std::cerr << "ioctl(SIOCGIFHWADDR) failed: " << std::strerror(errno) << std::endl;
            close(fd);
            continue;
        }
        close(fd);

        if (ifa->ifa_addr->sa_family == AF_INET)
        {
            struct sockaddr_in *sin = (struct sockaddr_in *)ifa->ifa_addr;
            // std::cout << "IP address: " << inet_ntoa(sin->sin_addr) << std::endl;
            std::string ip(inet_ntoa(sin->sin_addr));
            sin = (struct sockaddr_in *)ifa->ifa_netmask;
            // std::cout << "Netmask: " << inet_ntoa(sin->sin_addr) << std::endl;
            std::string netmask(inet_ntoa(sin->sin_addr));
            sin = (struct sockaddr_in *)ifa->ifa_ifu.ifu_broadaddr;
            if (sin != NULL)
            {
                Net *n = new Net;
                std::string ifname(ifa->ifa_name);
                std::vector<std::string> v_get = get_transmission(ifname);
                n = set_args(ifname, get_iftype(ifname), get_mac(ifname), ip, netmask, inet_ntoa(sin->sin_addr), get_gateway(ifname), v_get.at(1), v_get.at(0), v_get.at(3), v_get.at(2));
                v.push_back(*n);
                free(n);
            }
        }
        // std::cout << std::endl;
    }

    // 释放网络接口列表
    freeifaddrs(ifaddr);
    return v;
}
std::string get_mac(std::string ifname)
{
    struct ifreq ifreq;
    int sock = 0;
    char mac[32] = "";

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("error sock");
        return "";
    }

    strcpy(ifreq.ifr_name, ifname.c_str());
    if (ioctl(sock, SIOCGIFHWADDR, &ifreq) < 0)
    {
        perror("error ioctl");
        return "";
    }

    int i = 0;
    for (i = 0; i < 6; i++)
    {
        sprintf(mac + 3 * i, "%02X:", (unsigned char)ifreq.ifr_hwaddr.sa_data[i]);
    }
    mac[strlen(mac) - 1] = 0;
    std::string str_mac(mac);
    return str_mac;
}
std::string get_iftype(std::string ifname)
{
    if (ifname.at(0) == 'e')
    {
        return "Ethernet";
    }
    else if (ifname.at(0) == 'w')
    {
        return "Wireless";
    }
    else if (ifname.at(0) == 'l')
    {
        return "Local Loopback";
    }
    else if (ifname.at(0) == 'v')
    {
        return "Virtual Interface";
    }
    else
    {
        return "Unknown";
    }
}
std::string intToIp(unsigned int ip)
{
    struct in_addr addr;
    addr.s_addr = ip;
    return inet_ntoa(addr);
}
std::string get_gateway(std::string ifname)
{
    std::ifstream route_file("/proc/net/route");
    if (!route_file.is_open())
    {
        std::cerr << "Failed to open /proc/net/route" << std::endl;
        return "";
    }

    std::string line;
    std::getline(route_file, line); // Skip header line

    while (std::getline(route_file, line))
    {
        std::istringstream iss(line);
        std::string iface;
        unsigned int destination, gateway, mask;
        int other_fields;

        iss >> iface >> std::hex >> destination >> gateway;
        for (int i = 0; i < 5; ++i)
        {
            iss >> other_fields;
        }
        iss >> mask;
        if (ifname == iface)
        {
            route_file.close();
            return intToIp(gateway);
        }
        // std::cout << iface << "\t" << intToIp(destination) << "\t" << intToIp(gateway) << "\t" << intToIp(mask) << std::endl;
    }

    route_file.close();
    return "";
}
void getNetworkBytes(const std::string &interface, unsigned long long &received_bytes, unsigned long long &sent_bytes)
{
    std::ifstream proc_net_dev("/proc/net/dev");
    if (!proc_net_dev.is_open())
    {
        std::cerr << "Failed to open /proc/net/dev" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(proc_net_dev, line))
    {
        if (line.find(interface) != std::string::npos)
        {
            std::istringstream iss(line);
            std::string name;
            iss >> name >> received_bytes >> sent_bytes;
            break;
        }
    }
    proc_net_dev.close();
}
std::vector<std::string> get_transmission(std::string ifname)
{
    std::vector<std::string> v;
    if (ifname == "lo" || ifname == "eth0")
    {
        v.push_back("0");
        v.push_back("0");
        v.push_back("0");
        v.push_back("0");
        return v;
    }
    std::string interface = ifname;
    std::stringstream ss;
    int interval = 100000;

    unsigned long long received_bytes, sent_bytes;
    unsigned long long last_received_bytes = 0, last_sent_bytes = 0;
    unsigned long long received_speed;
    unsigned long long sent_speed;
    for (int i = 0; i < 2; i++)
    {
        getNetworkBytes(interface, received_bytes, sent_bytes);
        if (i == 0)
        {
            last_received_bytes = received_bytes;
            last_sent_bytes = sent_bytes;
            usleep(interval);
        }
        if (last_received_bytes != 0 || last_sent_bytes != 0)
        {
            received_speed = received_bytes - last_received_bytes;
            sent_speed = sent_bytes - last_sent_bytes;
        }
    }
    std::string str_received_speed;
    std::string str_sent_speed;
    ss << received_speed;
    ss >> str_received_speed;
    v.push_back(str_received_speed);
    ss.clear();
    ss << sent_speed;
    ss >> str_sent_speed;
    v.push_back(str_sent_speed);
    std::string str_received_bytes;
    std::string str_sent_bytes;
    ss.clear();
    ss << received_bytes;
    ss >> str_received_bytes;
    v.push_back(str_received_bytes);
    ss.clear();
    ss << sent_bytes;
    ss >> str_sent_bytes;
    v.push_back(str_sent_bytes);
    return v;
}
