#ifndef  SOFTWAREINFO_H
#define  SOFTWAREINFO_H
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


vector<Software>getSoftwareInfo();

#endif