#include "softwareinfo.h"

vector<Software>getSoftwareInfo()
{
	vector<Software> softwares;
	DIR *pDir;
	struct dirent* ptr;
	if(!(pDir = opendir("/usr/share/applications")))
	{
		cout<<"applications folder doesn't Exist!"<<endl;
		if(!(pDir = opendir("/usr/sbin")))
		{
			cout<<"sbin folder doesn't Exist!"<<endl;
			exit(0);
		}
	}
	while((ptr = readdir(pDir))!=0)
	{
		if (ptr->d_name[0]!='.')
		{
			Software software;
			software.name=ptr->d_name;
			softwares.push_back(software);
		}
	}
	closedir(pDir);
	return softwares;
}

// int main()
// {
// cout<<"=== software infomation ===\n";
// vector<Software> softwares;
// softwares=getFiles();
// for (int i = 0; i<softwares.size(); ++i)
// {
// softwares[i].tostring();
// }

// return 0;
// }