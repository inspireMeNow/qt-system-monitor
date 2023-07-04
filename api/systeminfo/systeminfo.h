#ifndef SYSTEMINFO_H
#define SYSTEMINFO_H
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include<sstream>

class System {
public:
    std::string distributor;
	std::string description;
	std::string release;
	std::string codename;
	void tostring()
	{
		std::cout<<"distributor:"<<distributor<<std::endl;
		std::cout<<"description:"<<description<<std::endl;
		std::cout<<"release:"<<release<<std::endl;
		std::cout<<"codename:"<<codename<<std::endl;
	}
};

//去除字符串中的""
std::string trim(std::string &s);

// ---- get System info ---- //
System getSystemInfo();

#endif