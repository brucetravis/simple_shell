#include "shell.h"

/**
  * execmd - function that excute
  * argv: the argument varible
  */

void execmd(char **argv)
{
	char *str = NULL, *command = NULL;

	if (argv)
	{
		str = argv[0];
		command = _path(str);

		if (execve(command, argv, NULL) == -1)
		{
			perror("Error");
		};
	}
}
