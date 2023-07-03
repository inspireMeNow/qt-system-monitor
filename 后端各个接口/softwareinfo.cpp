#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <vector>
#include <string>
using namespace std;

class Software
{
public:
	string name;
	void tostring()
	{
		cout<<"name:"<<name<<endl;
	}
};


vector<Software> getFiles()
{
	vector<Software> softwares;
	DIR *pDir;
    struct dirent* ptr;
    if(!(pDir = opendir("/usr/share/applications"))){
    // if(!(pDir = opendir(path.c_str()))){
        cout<<"Folder doesn't Exist!"<<endl;
        exit(0);
    }
    while((ptr = readdir(pDir))!=0) {
        if (ptr->d_name[0]!='.'){
			Software software;
			software.name=ptr->d_name;
            softwares.push_back(software);
    	}
    }
    closedir(pDir);
	return softwares;
}

int main() 
{
    cout<<"=== software infomation ===\n";
	vector<Software> softwares;
    softwares=getFiles();
	for (int i = 0; i<softwares.size(); ++i)
	{
		softwares[i].tostring();
	}

    return 0;
}