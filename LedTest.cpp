#include "LedTest.h"
#include "processinfo.h"

int LED_IS_STOP = 0;

bool LedTest(int led_no, int status)
{
	if (LED_IS_STOP == 0 && stop_process("led-player") == -1)
	{
		LED_IS_STOP = 1;
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
	/*通过系统调用 ioctl 和输入的参数控制 led*/
	ioctl(fd, status, led_no);
	/*关闭设备句柄*/
	close(fd);
	return true;
}