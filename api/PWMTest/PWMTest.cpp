#include "PWMTest.h"


void set_buzzer_freq(int option)
{
	int fd=-1;
	int freq=1000;
	fd = open("/dev/pwm", 0);
	if (fd < 0)
	{
		perror("open pwm_buzzer device");
		exit(1);
	}
// this IOCTL command is the key to set frequency
	if(option==0)
	{
		freq=500;
	}
	else if(option==1)
	{
		freq=1500;
	}
	int ret = ioctl(fd, PWM_IOCTL_SET_FREQ, freq);
	if(ret < 0)
	{
		perror("set the frequency of the buzzer");
		exit(1);
	}
	close(fd);
}

void close_buzzer()
{
	int fd=-1;
	fd = open("/dev/pwm", 0);
	if (fd < 0)
	{
		perror("open pwm_buzzer device");
		exit(1);
	}
	
	if (fd >= 0)
	{
		ioctl(fd, PWM_IOCTL_STOP);
		close(fd);
	}
}