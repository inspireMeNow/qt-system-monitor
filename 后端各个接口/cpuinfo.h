#ifndef CPUINFO_H
#define CPUINFO_H
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

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
string trim(string &s);


// ---- get cpu info ---- //
vector<CPU> getCpuInfo();

// int main() 
// {
    // printf("=== cpu infomation ===\n");
	// vector<CPU>cpus;
    // cpus=getCpuInfo();
	// cpu.tostring();
    // return 0;
// }
#endif