#include "ButtonTest.h"

Button ButtonTest()
{
	int buttons_fd;
	char buttons[6] = {'0', '0', '0', '0', '0', '0'};
	Button button;
	buttons_fd = open("/dev/buttons", 0);
	if (buttons_fd < 0)
	{
		perror("open device buttons");
		exit(1);
	}

	char current_buttons[6];
	int i;
	if (read(buttons_fd, current_buttons, sizeof current_buttons) != sizeof
	        current_buttons)
	{
		perror("read buttons:");
		exit(1);
	}
	for (i = 0; i < sizeof buttons / sizeof buttons[0]; i++)
	{
		if (buttons[i] != current_buttons[i])
		{
			buttons[i] = current_buttons[i];
			std::stringstream geek;
			std::string temp;
			geek<<buttons[i];
			geek>>temp;
			button.button_id=temp;
			button.status="按下";
		}
	}
	close(buttons_fd);
}