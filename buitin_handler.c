#include "shell.h"

/**
  * execute_builtin - buitlinn functions
  * @token: the args
  * @environ: the env
  * @lineptr: the line buffer
  **/

void execute_builtin(char **token, char **environ, char **lineptr)
{
	if (_strcmp(token[0], "exit") == 0)
	{
		free(*lineptr);
		exit(0);
	}
	else
	{
		fork_and_exec(token, environ, lineptr);
	}
}
