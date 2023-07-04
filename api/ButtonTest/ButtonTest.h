#ifndef BUTTONTEST_H
#define BUTTONTEST_H
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <errno.h>

#include <iostream>
#include <string>
#include <sstream>

class Button
{
public:
	std::string button_id;
	std::string status;

	void tostring()
	{
		std::cout<<"button "<<button_id<<" is "<<status<<std::endl;
	}
};

/*
	说明：
	该函数会返回你按下的那个按钮的状态，
	也就是说，返回的Button对象的status属性必然是"按下"，
	且只能返回最后按下的按钮的状态。
*/
Button ButtonTest();

#endif