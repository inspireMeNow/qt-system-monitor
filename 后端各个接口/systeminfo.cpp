#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include<sstream>

using namespace std;

class System {
public:
    string distributor;
	string description;
	string release;
	string codename;
	void tostring()
	{
		cout<<"distributor:"<<distributor<<endl;
		cout<<"description:"<<description<<endl;
		cout<<"release:"<<release<<endl;
		cout<<"codename:"<<codename<<endl;
	}
};

//去除字符串中的""
string trim(string &s) 
{
    if (!s.empty()) 
    {
		// cout<<"flag "<<s.find_last_not_of("\t")<<endl;
        s.erase(0,s.find_first_not_of("\""));
    	s.erase(s.find_last_not_of("\"") + 1);
    }
    return s;
}

// ---- get OS info ---- //
System getOSInfo() {
    System system;
    ifstream file;
	
	// read file line by line
	string temp;
	string name;
    string value;
	file.open("/etc/os-release");
    if (!file.good())
	{
		printf("failed to open os-release\n");
		file.open("/proc/version");
		if(!file.good())
		{
			cout<<"failed to open version"<<endl;
		}
		else
		{
			string tmp;
			getline(file,tmp);
			tmp=tmp.substr(0,tmp.find(")")+1);
			system.description=tmp;
			file.close();
			return system;
		}
	}
    
	
    while (getline(file,temp))
	{
		int pos=temp.find_first_of("=");
		// cout<<temp1<<endl;
		// cout<<"flag"<<pos<<endl;

		name=temp.substr(0,pos);
		value=temp.substr(pos+1);
		// cout<<"line"<<i++<<endl;
		// cout<<value<<endl;
		// name=trim(name);
		value=trim(value);
		// cout<<name<<"end"<<endl;
		if(name == "NAME")
		{
			system.distributor=value;
		}
		else if(name == "PRETTY_NAME")
		{
			system.description=value;
		}
		else if(name == "VERSION_ID")
		{
			system.release=value;
		}
		else if(name == "VERSION_CODENAME")
		{
			system.codename=value;
		}
    }
    file.close();
	return system;
}

int main() 
{
    printf("=== OS infomation ===\n");
	System sys;
    sys=getOSInfo();
	sys.tostring();
    return 0;
}