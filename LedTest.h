#ifndef LEDTEST_H
#define LEDTEST_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include <fcntl.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <sys/time.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>
#include <signal.h>
#include <ctype.h>

bool LedTest(int led_no,int status );

#endif