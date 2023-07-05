#include "LedTest.h"

void sigint_handler(int sig)
{
	start_process("led-player");
	exit(0);
}
int get_pid_by_name(const char *name)
{
	DIR *dir;
	struct dirent *ent;
	char buf[1024];
	char target[1024];
	int pid = -1;

	// 打开/proc目录
	if ((dir = opendir("/proc")) == NULL)
	{
		perror("opendir");
		return -1;
	}

	// 遍历/proc目录下的所有子目录
	while ((ent = readdir(dir)) != NULL)
	{
		// 如果子目录名称不是数字，则跳过
		if (!isdigit(*ent->d_name))
			continue;

		// 构造进程状态文件的路径
		sprintf(buf, "/proc/%s/status", ent->d_name);

		// 打开进程状态文件
		FILE *fp;
		if ((fp = fopen(buf, "r")) == NULL)
			continue;

		// 在进程状态文件中查找进程名称
		if (fgets(buf, sizeof(buf), fp) == NULL)
		{
			fclose(fp);
			continue;
		}
		sscanf(buf, "%*s %s", target);
		if (strcmp(target, name) == 0)
		{
			// 如果进程名称匹配，则获取进程ID并退出
			pid = atoi(ent->d_name);
			fclose(fp);
			break;
		}

		fclose(fp);
	}

	closedir(dir);

	return pid;
}
int start_process(const char *name)
{
	// int ret = system(name);
	// if (ret != 0)
	// {
	//     printf("Failed to start process\n");
	//     return -1;
	// }
	// return 0;
	pid_t pid = fork();
	if (pid == 0)
	{
		execl("/sbin/led-player", "led-player", NULL);
	}
	else
	{
		exit(0);
		kill(pid, SIGTERM);
	}
}
int stop_process(const char *name)
{
	// 中止原led灯控制程序
	int pid = get_pid_by_name(name);
	if (pid < 0)
	{
		printf("Failed to find process %s.\n", name);
		return -1;
	}
	else
	{
		// 向指定的进程发送SIGKILL信号，强制杀死进程
		if (kill(pid, SIGKILL) < 0)
		{
			printf("Failed to kill process %d.\n", pid);
			return -1;
		}

		printf("Process %d has been killed.\n", pid);
		return 0;
	}
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