#ifndef CPUINFO_H
#define CPUINFO_H
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>



class CPU {
public:
    std::string Processor;
    std::string BogoMIPS;
    std::string Features;
    std::string implementer;
    std::string architecture;
    std::string variant;
    std::string part;
    std::string revision;
    std::string Hardware;
	void tostring()
	{
        std::cout<<"Processor:"<<Processor<<std::endl;
        std::cout<<"BogoMIPS:"<<BogoMIPS<<std::endl;
        std::cout<<"Features:"<<Features<<std::endl;
        std::cout<<"CPU implementer:"<<implementer<<std::endl;
        std::cout<<"CPU architecture:"<<architecture<<std::endl;
        std::cout<<"CPU variant:"<<variant<<std::endl;
        std::cout<<"CPU part:"<<part<<std::endl;
        std::cout<<"CPU revision:"<<revision<<std::endl;
        std::cout<<"Hardware:"<<Hardware<<std::endl;
	}
};

//去除字符串中的制表符
std::string cpu_trim(std::string &s);


// ---- get cpu info ---- //
std::vector<CPU> getCpuInfo();

// int main() 
// {
    // printf("=== cpu infomation ===\n");
	// vector<CPU>cpus;
    // cpus=getCpuInfo();
	// cpu.tostring();
    // return 0;
// }
#endif
