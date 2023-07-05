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
vector<Env> getEnvInfo() {
	vector<Env> envs;
	
    FILE *fp;
	char buf[512];
	fp = popen("env", "r");
	fgets(buf,512, fp);
	string name;
	string value;
	while(fgets(buf,512,fp))
	{
		Env env;
		
		string s(buf);
		
		int pos=s.find("=");
		name=s.substr(0,pos);
		value=s.substr(pos+1);
		env.key=name;
		env.value=value;
		
		// env.tostring();
		envs.push_back(env);
	}
	pclose(fp);
	return envs;
}

int main() 
{
    printf("=== env infomation ===\n");
	vector<Env> envs;
    envs=getEnvInfo();
	for (int i = 0; i<envs.size(); ++i)
	{
		envs[i].tostring();
	}

    return 0;
}