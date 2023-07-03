#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>
#include <signal.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <ctype.h>
typedef struct process
{
    std::string user;
    int pid;
    std::string command;
    std::string processperc;
    std::string memperc;
    std::string start;
    std::string time;
} process;
process *set_args(std::string user, int pid, std::string command, std::string processperc, std::string memperc, std::string start, std::string time)
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
        int uid;
        char command[100], pid[100];
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
                sscanf(buf, "%*s %s", pid);
            }
            else if (str_buf.find("Uid:") == 0)
            {
                std::istringstream iss(str_buf.substr(5));
                iss >> uid >> uid >> uid >> uid;
            }
        }
        process *p = new process;
        p = set_args("root", std::atoi(pid), command, "0.0", "0.0", "2019", "00:00:00");
        // std::cout << p->user << " " << p->pid << " " << p->command << " " << p->processperc << " " << p->memperc << " " << p->start << " " << p->time << std::endl;
        v.push_back(*p);
        free(p);
        fclose(fp);
    }
    closedir(dir);

    return v;
}
int start_process(const char *name)
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

        execl("/sbin/led-player", "led-player", NULL);
    }
    else
    {
        exit(0);
        kill(pid, SIGTERM);
    }
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