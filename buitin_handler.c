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
	if (_strcmp(token[0], "env") == 0)
         {
                 execut_env(environ);
                 exit(0);
         }
	else
	{
		fork_and_exec(token, environ, lineptr);
	}
}

void execut_env(char **environ)
{
        char **ptr = environ;

	while (*ptr != NULL)
        {
            write(STDOUT_FILENO, *ptr, _strlen(*ptr));
            write(STDOUT_FILENO, "\n", 1);
                ptr++;
        }
}
