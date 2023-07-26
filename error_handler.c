#include "shell.h"
/**
  * command_err - function that handles command err
  * @str: the command
  */

void command_err(const char *str)
{
	const char err_msg[] = "./shell: No such file or directory";

	(void)str;
	write(2, err_msg, sizeof(err_msg) - 1);
	/*write(2, str, strlen(str));*/
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}
