#include "shell.h"
/**
  * command_err - function that handles command err
  * @str: the command
  */

void command_err(const char *str)
{
	char err_msg[] = "./hsh: 1: ";
	char not_found_msg[] = ": not found\n";

	write(2, err_msg, sizeof(err_msg) - 1);
	write(2, str, strlen(str));
	write(2, not_found_msg, sizeof(not_found_msg) - 1);
	exit(127);
}
