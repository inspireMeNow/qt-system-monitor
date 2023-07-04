#include <iostream>  
#include <fstream> 
#include <sstream> 
#include <string>  
#include <ctime>  
#include <unistd.h>  
  
long getProcessStartTime(int pid) {  
    std::stringstream s;
    s << pid;
    std::string str_pid = s.str();
    std::ifstream stat_file(std::string("/proc/" + str_pid + "/stat").c_str());  
    if (!stat_file.is_open()) {  
        std::cerr << "Failed to open /proc/" << pid << "/stat" << std::endl;  
        return -1;  
    }  
  
    std::string field;  
    for (int i = 1; i <= 22; ++i) {  
        stat_file >> field;  
    }  
    stat_file.close();  
    std::stringstream ss(field);
    long process_start_time;  
    ss >> process_start_time;
    long clock_ticks_per_second = sysconf(_SC_CLK_TCK);  
  
    return process_start_time / clock_ticks_per_second;  
}  
  
int main() {  
    int pid;  
    std::cout << "Enter the PID of the process: ";  
    std::cin >> pid;  
  
    long process_start_time_since_boot = getProcessStartTime(pid);  
    if (process_start_time_since_boot < 0) {  
        return 1;  
    }  
  
    std::ifstream uptime_file("/proc/uptime");  
    if (!uptime_file.is_open()) {  
        std::cerr << "Failed to open /proc/uptime" << std::endl;  
        return 1;  
    }  
  
    double uptime_seconds;  
    uptime_file >> uptime_seconds;  
    uptime_file.close(); 
  
    double process_start_time_seconds = uptime_seconds - process_start_time_since_boot;  
    std::time_t process_start_time = std::time(NULL) - static_cast<std::time_t>(process_start_time_seconds);  
    std::cout<<process_start_time_seconds<<" ";
    std::cout << "Process " << pid << " started at: " << std::asctime(std::localtime(&process_start_time)) << std::endl;  
  
    return 0;  
}  
