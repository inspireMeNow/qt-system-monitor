#include "cpuinfo.h"


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
vector<CPU> getCpuInfo() {
	vector<CPU> cpus;
    ifstream file;
	file.open("/proc/cpuinfo");
    if (!file.good())
        printf("failed to open cpuinfo\n");    
    // read file line by line
	string temp;
	string name;
    string value;
	int i=0;
	CPU cpu;
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
	cpus.push_back(cpu);
    file.close();
	return cpus;
}

// int main() 
// {
    // printf("=== cpu infomation ===\n");
	// vector<CPU>cpus;
    // cpus=getCpuInfo();
	// cpu.tostring();
    // return 0;
// }