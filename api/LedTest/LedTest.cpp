#include "LedTest.h"

using namespace std;
void LedTest(int led_no,int status )
{
	int fd;
	/*打开/dev/leds 设备文件*/
	fd = open("/dev/leds0", 0);
	if (fd < 0)
	{
		fd = open("/dev/leds", 0);
	}
	if (fd < 0)
	{
		perror("open device leds");
		exit(1);
	}
	/*通过系统调用 ioctl 和输入的参数控制 led*/
	ioctl(fd, status, led_no);
	/*关闭设备句柄*/
	close(fd);
}