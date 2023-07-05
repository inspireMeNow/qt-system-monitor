#include "ButtonTest.h"


std::string BeginButtonTest()
{
	std::string str="";
	int buttons_fd;
	char buttons[4] = {'0', '0', '0', '0'};
	buttons_fd = open("/dev/buttons", 0);
	if (buttons_fd < 0)
	{
		perror("open device buttons");
		exit(1);
	}

	char current_buttons[6];
	int count_of_changed_key;
	int i;
	if (read(buttons_fd, current_buttons, sizeof current_buttons) != sizeof
	        current_buttons)
	{
		perror("read buttons:");
		exit(1);
	}
	for (i = 0, count_of_changed_key = 0; i < sizeof buttons / sizeof buttons[0]; i++)
	{
		if (buttons[i] != current_buttons[i])
		{
			buttons[i] = current_buttons[i];
			char temp[100];
			sprintf(temp,"%skey %d is %s\n", count_of_changed_key? ", ": "", i+1, buttons[i]
			        == '0' ? "up" : "down");
			str+=temp;
			count_of_changed_key++;
		}
	}
	close(buttons_fd);
	return str;
}