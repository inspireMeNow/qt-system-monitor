#include "memoryinfo.h"

using namespace std;
//去除字符串中的制表符
std::string trim(std::string &s) 
{
    if (!s.empty()) 
    {
		// cout<<"flag "<<s.find_last_not_of("\t")<<endl;
        s.erase(0,s.find_first_not_of(" "));
    	s.erase(s.find_last_not_of("\t") + 1);
    }
    return s;
}

// ---- get memory info ---- //
std::vector<Memory> getMemoryInfo() {
	std::vector<Memory> memories;

    ifstream file;
	file.open("/proc/meminfo");
    if (!file.good())
        printf("failed to open meminfo\n");
    
    // read file line by line
	std::string temp;
	std::string name;
    std::string value;
	
	// 用于将字符串转为整型
	
	int temp1=0;
	Memory memory;
	memory.id="0";
    while (getline(file,temp))
	{   
		int pos=temp.find_first_of(":");
		// cout<<temp1<<endl;
		// cout<<"flag"<<pos<<endl;

		name=temp.substr(0,pos);
		value=temp.substr(pos+1);
		// cout<<"line"<<i++<<endl;
		// cout<<value<<endl;
		// name=trim(name);
		value=trim(value);
		// cout<<name<<"end"<<endl;
		if(name == "MemTotal")
		{
			stringstream geek;
			geek<<value;
			geek>>temp1;
			temp1=temp1/1024;
			stringstream geek1;
			geek1<<temp1;
			geek1>>memory.total;
			memory.total=memory.total+" MB";
		}
		else if(name == "MemFree")
		{
			stringstream geek;
			geek<<value;
			geek>>temp1;
			// cout<<temp1<<endl;
			temp1=temp1/1024;
			stringstream geek1;
			geek1<<temp1;
			geek1>>memory.free;
			memory.free=memory.free+" MB";
		}
		else if(name == "Active")
		{
			stringstream geek;
			geek<<value;
			geek>>temp1;
			// cout<<temp1<<endl;
			temp1=temp1/1024;
			
			stringstream geek1;
			int a=0;
			geek1<<memory.total;
			geek1>>a;
			// cout<<"a"<<a<<" b"<<temp1<<endl;
			stringstream geek2;
			geek2<<(a-temp1);
			geek2>>memory.used;
			memory.used=memory.used+" MB";
		}
		else if(name == "Inactive")
		{
			stringstream geek;
			geek<<value;
			geek>>temp1;
			temp1=temp1/1024;
			stringstream geek1;
			geek1<<temp1;
			geek1>>memory.shared;
			memory.shared=memory.shared+" MB";
		}
		else if(name == "Cached")
		{
			stringstream geek;
			geek<<value;
			geek>>temp1;
			temp1=temp1/1024;
			stringstream geek1;
			geek1<<temp1;
			geek1>>memory.cache;
			memory.cache=memory.cache+" MB";
		}		
    }
	memories.push_back(memory);
    file.close();
	return memories;
}

/* int main() 
{
    printf("=== memory infomation ===\n");
	Memory memory;
    memory=getMemoryInfo();
	memory.tostring();
    return 0;
} */
