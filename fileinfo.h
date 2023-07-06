#ifndef FIFEINFO_H
#define FIFEINFO_H
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include<sstream>
#include<vector>


class File {
public:
    std::string filesys;
    std::string size;
    std::string used;
    std::string avail;
    std::string userdperc;
    std::string mounted;
	
	void tostring()
	{
        std::cout<<"filesys:"<<filesys<<std::endl;
        std::cout<<"size:"<<size<<std::endl;
        std::cout<<"used:"<<used<<std::endl;
        std::cout<<"avail:"<<avail<<std::endl;
        std::cout<<"userdperc:"<<userdperc<<std::endl;
        std::cout<<"mounted:"<<mounted<<std::endl;
	}
};

//去除字符串中的空格
std::string trim(std::string &s);

// ---- get file info ---- //
std::vector<File> getFileInfo();

#endif
