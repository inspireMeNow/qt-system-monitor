#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class CPU {
public:
	string Processor;
	string BogoMIPS;
	string Features;
	string implementer;
	string architecture;
	string variant;
	string part;
	string revision;
	string Hardware;
	void tostring()
	{
		cout<<"Processor:"<<Processor<<endl;
		cout<<"BogoMIPS:"<<BogoMIPS<<endl;
		cout<<"Features:"<<Features<<endl;
		cout<<"CPU implementer:"<<implementer<<endl;
		cout<<"CPU architecture:"<<architecture<<endl;
		cout<<"CPU variant:"<<variant<<endl;
		cout<<"CPU part:"<<part<<endl;
		cout<<"CPU revision:"<<revision<<endl;
		cout<<"Hardware:"<<Hardware<<endl;
	}
};

//去除字符串中的制表符
string trim(string &s) 
{
    if (!s.empty()) 
    {
		// cout<<"flag "<<s.find_last_not_of("\t")<<endl;
        s.erase(0,s.find_first_not_of(" "));
    	s.erase(s.find_last_not_of("\t") + 1);
    }
    return s;
}


// ---- get cpu info ---- //
CPU getCpuInfo() {
    CPU cpu;
    ifstream file;
	file.open("/proc/cpuinfo");
    if (!file.good())
        printf("failed to open cpuinfo\n");
    
    // read file line by line
	string temp;
	string name;
    string value;
	int i=0;
    while (getline(file,temp))
	{
		// trim(temp);
		// cout<<temp.length()<<endl;
		int pos=temp.find_first_of(":");
		if(temp=="")
		{
			continue;
		}
		name=temp.substr(0,pos-1);
		value=temp.substr(pos+1);
		// string s;
		name=trim(name);
		value=trim(value);
		// cout<<name<<"end"<<endl;
		if(name=="Processor")
		{
			cpu.Processor=value;
		}
		else if(name == "BogoMIPS")
		{
			cpu.BogoMIPS=value;
		}
		else if(name == "Features")
		{
			cpu.Features=value;
		}
		else if(name == "CPU implementer")
		{
			cpu.implementer=value;
		}
		else if(name == "CPU architectur")
		{
			cpu.architecture=value;
		}
		else if(name == "CPU variant")
		{
			cpu.variant=value;
		}
		else if(name == "CPU part")
		{
			cpu.part=value;
		}
		else if(name == "CPU revision")
		{
			cpu.revision=value;
		}
		else if(name == "Hardware")
		{
			cpu.Hardware=value;
		}		
    }
    file.close();
	return cpu;
}

int main() 
{
    printf("=== cpu infomation ===\n");
	CPU cpu;
    cpu=getCpuInfo();
	cpu.tostring();
    return 0;
}