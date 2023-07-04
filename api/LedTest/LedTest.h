#ifndef LEDTEST_H
#define LEDTEST_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include <fcntl.h>

void LedTest(int led_no,int status );

#endif