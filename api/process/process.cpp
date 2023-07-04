#include "process.h"
process *set_args(std::string user, int pid, std::string command, double processperc, int memperc, double start, std::string time)
{
    process *p = new process;
    p->user = user;
    p->pid = pid;
    p->command = command;
    p->processperc = processperc;
    p->memperc = memperc;
    p->start = start;
    p->time = time;
    return p;
}
int get_pid_by_name(const char *name)
{
    DIR *dir;
    struct dirent *ent;
    char buf[1024];
    char target[1024];
    int pid = -1;
    process p;
    // 打开/proc目录
    if ((dir = opendir("/proc")) == NULL)
    {
        perror("opendir");
        return -1;
    }

    // 遍历/proc目录下的所有子目录
    while ((ent = readdir(dir)) != NULL)
    {
        // 如果子目录名称不是数字，则跳过
        if (!isdigit(*ent->d_name))
            continue;

        // 构造进程状态文件的路径
        sprintf(buf, "/proc/%s/status", ent->d_name);
        // 打开进程状态文件
        FILE *fp;
        if ((fp = fopen(buf, "r")) == NULL)
            continue;

        // 在进程状态文件中查找进程名称
        if (fgets(buf, sizeof(buf), fp) == NULL)
        {
            fclose(fp);
            continue;
        }
        sscanf(buf, "%*s %s", target);
        if (strcmp(target, name) == 0)
        {
            // 如果进程名称匹配，则获取进程ID并退出
            pid = atoi(ent->d_name);
            fclose(fp);
            break;
        }

        fclose(fp);
    }

    closedir(dir);

    return pid;
}
std::vector<process> get_pid()
{
    DIR *dir;
    struct dirent *ent;
    char buf[1024];
    char target[1024];
    std::string command;
    std::vector<process> v;
    // 打开/proc目录
    if ((dir = opendir("/proc")) == NULL)
    {
        perror("opendir");
        return std::vector<process>();
    }

    // 遍历/proc目录下的所有子目录
    while ((ent = readdir(dir)) != NULL)
    {
        // 如果子目录名称不是数字，则跳过
        if (!isdigit(*ent->d_name))
            continue;

        // 构造进程状态文件的路径
        sprintf(buf, "/proc/%s/status", ent->d_name);
        // 打开进程状态文件
        FILE *fp;
        if ((fp = fopen(buf, "r")) == NULL)
            continue;
        int uid, pid;
        char command[100], str_pid[100], *user;
        double cpu_usage;
        while (fgets(buf, sizeof(buf), fp))
        {
            std::string str_buf = buf;
            if (str_buf.find("Name:") == 0)
            {
                sscanf(buf, "%*s %s", command);
                // printf("%s\n",command);
            }
            else if (str_buf.find("Pid:") == 0)
            {
                sscanf(buf, "%*s %s", str_pid);
                std::stringstream ss(str_pid);
                ss >> pid;
            }
            else if (str_buf.find("Uid:") == 0)
            {
                std::istringstream iss(str_buf.substr(5));
                iss >> uid >> uid >> uid >> uid;
                std::string str_uid;
                std::stringstream ss;
                ss << uid;
                ss >> str_uid;
                char *char_uid = new char[str_uid.length() + 1];
                strcpy(char_uid, str_uid.c_str());
                user = find_process_uid(char_uid);
                free(char_uid);
            }
            cpu_usage = getProcessCpuUsage(pid); // 获取进程cpu使用率
        }
        process *p = new process;
        std::map<double, std::string> map = getRuntime(pid);
        p = set_args(user, pid, command, cpu_usage * 100, get_proc_mem(pid), map.begin()->first, map.begin()->second);
        // std::cout << p->user << " " << p->pid << " " << p->command << " " << p->processperc << " " << p->memperc << " " << p->start << " " << p->time << std::endl;
        v.push_back(*p);
        free(p);
        free(user);
        fclose(fp);
    }
    closedir(dir);

    return v;
}
int start_process(char *name)
{
    // int ret = system(name);
    // if (ret != 0)
    // {
    //     printf("Failed to start process\n");
    //     return -1;
    // }
    // return 0;
    pid_t pid = fork();
    if (pid == 0)
    {

        execl(name, name, NULL);
    }
    else
    {
        exit(0);
        kill(pid, SIGTERM);
    }
}
char *find_process_uid(const char *uid)
{
    FILE *fp;
    char buf[1024];
    char filename[] = "/etc/passwd";
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Failed to open file %s\n", filename);
        return NULL;
    }
    while (fgets(buf, sizeof(buf), fp))
    {
        int count = 0;
        int flag = 0;
        int left = 0, right = 0;
        for (int i = 0; buf[i] != '\0' && count <= 2; i++)
        {
            if (buf[i] == ':')
            {
                count++;
            }
            if (count == 2)
            {
                left = i;
                for (int j = i + 1;; j++)
                {
                    if (buf[j] == ':')
                    {
                        right = j;
                        count++;
                        break;
                    }
                }
            }
        }
        char str[10];
        int i = 0;
        for (i = 0; i < right - left - 1; i++)
        {
            str[i] = buf[i + left + 1];
        }
        str[i] = '\0';
        char *user = NULL;
        user = (char *)malloc(sizeof(char) * 100);
        if (strcmp(str, uid) == 0)
        {
            for (int i = 0; buf[i] != '\0'; i++)
            {
                user[i] = buf[i];
                if (buf[i] == ':')
                {
                    user[i] = '\0';
                    return user;
                }
            }
        }
    }
    return "";
}
int stop_process(const char *name)
{
    int pid = get_pid_by_name(name);
    if (pid < 0)
    {
        printf("Failed to find process %s.\n", name);
        return -1;
    }
    else
    {
        if (kill(pid, SIGKILL) < 0)
        {
            printf("Failed to kill process %d.\n", pid);
            return -1;
        }

        printf("Process %d has been killed.\n", pid);
        return 0;
    }
}

// 获取进程占用内存
unsigned int get_proc_mem(unsigned int pid)
{

    char file_name[64] = {0};
    FILE *fd;
    char line_buff[512] = {0};
    sprintf(file_name, "/proc/%d/status", pid);

    fd = fopen(file_name, "r");
    if (NULL == fd)
    {
        return 0;
    }

    char name[64];
    int vmrss;
    for (int i = 0; i < VMRSS_LINE - 1; i++)
    {
        fgets(line_buff, sizeof(line_buff), fd);
    }

    fgets(line_buff, sizeof(line_buff), fd);
    sscanf(line_buff, "%s %d", name, &vmrss);
    fclose(fd);

    return vmrss;
}

double getProcessCpuUsage(int pid)
{
    std::stringstream s;
    s << pid;
    std::string str_pid = s.str();
    std::string stat_path = "/proc/" + str_pid + "/stat";
    std::ifstream stat_file(stat_path.c_str());
    if (!stat_file.is_open())
    {
        std::cerr << "Failed to open " << stat_path << std::endl;
        return -1;
    }

    long utime, stime;
    std::string field;
    for (int i = 1; i <= 13; ++i)
    {
        stat_file >> field;
    }
    stat_file >> utime >> stime;
    stat_file.close();

    long total_time = utime + stime;

    std::ifstream stat_file2("/proc/stat");
    if (!stat_file2.is_open())
    {
        std::cerr << "Failed to open /proc/stat" << std::endl;
        return -1;
    }

    std::string cpu_str;
    long user, nice, system, idle;
    stat_file2 >> cpu_str >> user >> nice >> system >> idle;
    stat_file2.close();

    long total_cpu_time = user + nice + system + idle;

    return static_cast<double>(total_time) / total_cpu_time;
}
long getProcessStartTime(int pid)
{
    std::stringstream s;
    s << pid;
    std::string str_pid = s.str();
    std::ifstream stat_file(std::string("/proc/" + str_pid + "/stat").c_str());
    if (!stat_file.is_open())
    {
        std::cerr << "Failed to open /proc/" << pid << "/stat" << std::endl;
        return -1;
    }

    std::string field;
    for (int i = 1; i <= 22; ++i)
    {
        stat_file >> field;
    }
    stat_file.close();
    std::stringstream ss(field);
    long process_start_time;
    ss >> process_start_time;
    long clock_ticks_per_second = sysconf(_SC_CLK_TCK);

    return process_start_time / clock_ticks_per_second;
}
std::map<double, std::string> getRuntime(int pid)
{

    long process_start_time_since_boot = getProcessStartTime(pid);
    if (process_start_time_since_boot < 0)
    {
        return std::map<double, std::string>();
    }

    std::ifstream uptime_file("/proc/uptime");
    if (!uptime_file.is_open())
    {
        std::cerr << "Failed to open /proc/uptime" << std::endl;
        return std::map<double, std::string>();
    }

    double uptime_seconds;
    uptime_file >> uptime_seconds;
    uptime_file.close();

    double process_start_time_seconds = uptime_seconds - process_start_time_since_boot;
    std::time_t process_start_time = std::time(NULL) - static_cast<std::time_t>(process_start_time_seconds);
    // std::cout << process_start_time_seconds << " ";
    // std::cout << "Process " << pid << " started at: " << std::asctime(std::localtime(&process_start_time)) << std::endl;
    char time_str[100];
    std::strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", std::localtime(&process_start_time));
    std::string time_string(time_str);
    std::map<double, std::string> map;
    map[process_start_time_seconds] = time_string;
    return map;
}