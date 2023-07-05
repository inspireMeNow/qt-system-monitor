#ifndef ENV_H
#define ENV_H
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <vector>
#include <string>


class Software
{
public:
    std::string name;
    void tostring()
    {
        std::cout<<"name:"<<name<<std::endl;
    }
};


std::vector<Software>getSoftwareInfo();

#endif
