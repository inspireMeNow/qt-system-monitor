#ifndef MEMORYINFO_H
#define MEMORYINFO_H
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include<sstream>
#include <vector>

class Memory {
public:
    std::string id;
    std::string total;
    std::string used;
    std::string free;
    std::string shared;
    std::string cache;
	void tostring()
	{
		std::cout<<"id:"<<id<<std::endl;
		std::cout<<"total:"<<total<<std::endl;
		std::cout<<"used:"<<used<<std::endl;
		std::cout<<"free:"<<free<<std::endl;
		std::cout<<"shared:"<<shared<<std::endl;
		std::cout<<"cache:"<<cache<<std::endl;
	}
};

//去除字符串中的制表符
std::string memory_trim(std::string &s);

// ---- get memory info ---- //
std::vector<Memory> getMemoryInfo();

#endif
