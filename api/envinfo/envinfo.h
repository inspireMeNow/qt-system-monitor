#ifndef ENV_H
#define ENV_H
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include<sstream>
#include<vector>

using namespace std;

class Env {
public:
    string key;
    string value;
	
	void tostring()
	{
		cout<<"key:"<<key<<endl;
		cout<<"value:"<<value<<endl;
	}
};

// ---- get Env info ---- //
vector<Env> getEnvInfo();

#endif