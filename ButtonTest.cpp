#include "ButtonTest.h"

int buttons_fd=-1;

std::string BeginButtonTest()
{
	std::string str = "";
	char buttons[6] = {'0', '0', '0', '0', '0', '0'};
	char current_buttons[6];
	int count_of_changed_key;
	int i;
	if (read(buttons_fd, current_buttons, sizeof(current_buttons)) != sizeof(current_buttons))
	{
		perror("read buttons:");
		exit(1);
	}
	for (i = 0, count_of_changed_key = 0; i < sizeof(buttons) / sizeof(buttons[0]); i++)
	{
		if (buttons[i] != current_buttons[i])
		{
			buttons[i] = current_buttons[i];
			str="key ";
			std::string temp;
			if(buttons[i]=='0')
			{
				std::stringstream ss;
				ss<<i+1;
				ss>>temp;
				str+=temp+" is up";
			}
			else
			{
				std::stringstream ss;
				ss<<i+1;
				ss>>temp;
				str+=temp+" is down";
			}
		}
	}
	// close(buttons_fd);
	return str;
}
void open_button()
{
	if (buttons_fd >= 0)
	{
		return;
	}
	buttons_fd = open("/dev/buttons", 0);
	if (buttons_fd < 0)
	{
		perror("open device buttons");
		exit(1);
	}
}
