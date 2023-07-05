#include "fileinfo.h"

//去除字符串中的空格
string trim(string &s) 
{
	string tmp;
    if (!s.empty()) 
    {
		int i=0;
		int flag=0;
		while(s[i]!='\0')
		{
			if(s[i]!=' ')
			{
				tmp=tmp+s[i];
				flag=0;
			}
			else
			{
				if(flag==0)
				{
					flag=1;
					tmp=tmp+':';
				}
			}
			i++;
		}
    }
    return tmp;
}

// ---- get file info ---- //
vector<File> getFileInfo() {
	vector<File> files;
	
    FILE *fp;
	char buf[512];
	fp = popen("df -h", "r");
	fgets(buf,512, fp);
	string value;
	while(fgets(buf,512,fp))
	{
		File file;
		int pos;
		string s(buf);
		s=trim(s);
		pos=s.find(":");
		value=s.substr(0,pos);
		s=s.substr(pos+1);
		// cout<<s<<endl;
		file.filesys=value;
		
		pos=s.find(":");
		value=s.substr(0,pos);
		s=s.substr(pos+1);
		// cout<<s<<endl;
		file.size=value;
		
		pos=s.find(":");
		value=s.substr(0,pos);
		s=s.substr(pos+1);
		file.used=value;
		
		pos=s.find(":");
		value=s.substr(0,pos);
		s=s.substr(pos+1);
		file.avail=value;
		
		pos=s.find(":");
		value=s.substr(0,pos);
		s=s.substr(pos+1);
		file.userdperc=value;
		
		pos=s.find(":");
		value=s.substr(0,pos);
		s=s.substr(pos+1);
		file.mounted=value;
		
		// file.tostring();
		files.push_back(file);
	}
	pclose(fp);
	return files;
}

/* int main() 
{
    printf("=== file infomation ===\n");
	vector<File> files;
    files=getFileInfo();
	for (int i = 0; i<files.size(); ++i)
	{
		files[i].tostring();
	}

	// file.tostring();
    return 0;
} */