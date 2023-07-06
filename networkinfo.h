#ifndef NET_H
#define NET_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>  
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <net/if.h>
#include <vector>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <ifaddrs.h>
#include <iomanip>
#include <cerrno>
typedef struct Net {
    std::string ifname;
    std::string iftype;
    std::string mac;
    std::string ip;
    std::string mask;
    std::string broadcast;
    std::string gateway;
    std::string upload_speed;
    std::string download_speed;
    std::string upload_bytes;
    std::string download_bytes;
}Net;
std::vector<Net> get_net();
std::string get_mac(std::string ifname);
std::string get_iftype(std::string ifname);
std::string intToIp(unsigned int ip);
std::string get_gateway(std::string ifname);
void getNetworkBytes(const std::string& interface, unsigned long long& received_bytes, unsigned long long& sent_bytes);
std::vector<std::string> get_transmission(std::string ifname);
#endif
