#include "LedTest.h"
#include "processinfo.h"
void sigint_handler(int sig)
{
	start_process("led-player");
	exit(0);
}

bool LedTest(int led_no, int status)
{
	if (stop_process("led-player") == -1)
	{
		return false;
	}
	int fd;
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
	signal(SIGINT, sigint_handler);
	/*通过系统调用 ioctl 和输入的参数控制 led*/
	ioctl(fd, status, led_no);
	/*关闭设备句柄*/
	close(fd);
	return true;
}