#include "shell.h"

/**
  * execute_builtin - buitlinn functions
  * @token: the args
  * @environ: the env
  **/

void execute_builtin(char **token, char **environ)
{
	if (_strcmp(token[0], "exit") == 0)
	{
		execute_exit(0);
	}
	else
	{
		fork_and_exec(token, environ);
	}
}

/**
  * execute_exit - exit function
  * @status: the status
  */

void execute_exit(int status)
{
	exit(status);
}
