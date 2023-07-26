#include "shell.h"

/**
  * execmd - function that excute
  * @argv: the argument varible
  */

void execmd(char **argv, char **environ)
{
	char *str = NULL;

	if (argv)
	{
		str = argv[0];
		/*command = _path(str);*/

		if (execve(str, argv, environ) == -1)
		{
			perror("Error");
		};
	}
}

/**
  * fork_and_exec - fork function
  * @argv: the argument
 */

void fork_and_exec(char **argv, char **environ)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		execmd(argv, environ);
		exit(EXIT_SUCCESS);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status == EXIT_SUCCESS))
		{
			int exit_status = WEXITSTATUS(status);
			exit(exit_status);
		}
	}
}
