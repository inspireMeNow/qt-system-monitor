#ifndef PWMTEST_H
#define PWMTEST_H
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#define PWM_IOCTL_SET_FREQ 1
#define PWM_IOCTL_STOP 2
#define ESC_KEY 0x1b

#include <fcntl.h>
#include <sys/ioctl.h>

void set_buzzer_freq(int option=-1);

void close_buzzer();

#endif