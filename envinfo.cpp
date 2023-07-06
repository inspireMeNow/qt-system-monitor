#include "envinfo.h"

std::vector<Software>getSoftwareInfo()
{
    std::vector<Software> softwares;
    DIR *pDir;
    struct dirent* ptr;
    if(!(pDir = opendir("/usr/share/applications")))
    {
        std::cout<<"applications folder doesn't Exist!"<<std::endl;
        if(!(pDir = opendir("/usr/sbin")))
        {
            std::cout<<"sbin folder doesn't Exist!"<<std::endl;
            exit(0);
        }
    }
    while((ptr = readdir(pDir))!=0)
    {
        if (ptr->d_name[0]!='.')
        {
            Software software;
            software.name=ptr->d_name;
            softwares.push_back(software);
        }
    }
    closedir(pDir);
    return softwares;
}

// int main()
// {
// cout<<"=== software infomation ===\n";
// vector<Software> softwares;
// softwares=getFiles();
// for (int i = 0; i<softwares.size(); ++i)
// {
// softwares[i].tostring();
// }

// return 0;
// }
