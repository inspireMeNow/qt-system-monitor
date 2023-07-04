#ifndef FIFEINFO_H
#define FIFEINFO_H
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include<sstream>
#include<vector>

using namespace std;

class File {
public:
    string filesys;
	string size;
	string used;
	string avail;
	string userdperc;
	string mounted;
	
	void tostring()
	{
		cout<<"filesys:"<<filesys<<endl;
		cout<<"size:"<<size<<endl;
		cout<<"used:"<<used<<endl;
		cout<<"avail:"<<avail<<endl;
		cout<<"userdperc:"<<userdperc<<endl;
		cout<<"mounted:"<<mounted<<endl;
	}
};

//去除字符串中的空格
string trim(string &s);

// ---- get file info ---- //
vector<File> getFileInfo();

#endif