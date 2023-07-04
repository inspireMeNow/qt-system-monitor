#ifndef PROCESS_H
#define PROCESS_H

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
#include <map>
#include <ctime>

#define VMRSS_LINE 17

typedef struct process
{
    std::string user;    // 用户
    int pid;             // 进程号
    std::string command; // 进程名
    double processperc;   // CPU占用百分比
    int memperc; // 内存占用
    double start;   // 启动时间
    std::string time;    // 运行时间
} process;

process *set_args(std::string user, int pid, std::string command, std::string processperc, std::string memperc, std::string start, std::string time);
int get_pid_by_name(const char *name);
std::vector<process> get_pid();
int start_process(const char *name);
char *find_process_uid(const char *uid);
int stop_process(const char *name);
double getProcessCpuUsage(int pid);
const char *get_items(const char *buffer, unsigned int item);
unsigned int get_proc_mem(unsigned int pid);
long getProcessStartTime(int pid);
std::map<double, std::string> getRuntime(int pid);
#endif