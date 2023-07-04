#include <iostream>  
#include <fstream> 
#include <sstream> 
#include <string>  
#include <unistd.h> 

double getProcessCpuUsage(int pid) {  
    std::stringstream s;
    s << pid;
    std::string str_pid = s.str();
    std::string stat_path = "/proc/" + str_pid + "/stat";  
    std::ifstream stat_file(stat_path.c_str());  
    if (!stat_file.is_open()) {  
        std::cerr << "Failed to open " << stat_path << std::endl;  
        return -1;  
    }  
  
    long utime, stime;  
    std::string field;  
    for (int i = 1; i <= 13; ++i) {  
        stat_file >> field;  
    }  
    stat_file >> utime >> stime;  
    stat_file.close();  
  
    long total_time = utime + stime;  
  
    std::ifstream stat_file2("/proc/stat");  
    if (!stat_file2.is_open()) {  
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
  
int main() {  
    int pid;  
    std::cout << "Enter the PID of the process: ";  
    std::cin >> pid;  
  
    while (true) {  
        double cpu_usage = getProcessCpuUsage(pid);  
        if (cpu_usage < 0) {  
            return 1;  
        }  
  
        std::cout << "CPU usage for process " << pid << ": " << cpu_usage * 100 << "%" << std::endl;  
  
        // std::this_thread::sleep_for(std::chrono::seconds(1)); 
        sleep(1); 
    }  
  
    return 0;  
}  
