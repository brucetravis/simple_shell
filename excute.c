#include "shell.h"

/**
  * execmd - functions that excute
  * @argv: the argument varible
  * @environ: environment variable used
  */

void execmd(char **argv, char **environ)
{
	if (argv && argv[0])
	{
		char *str = argv[0];
		char *execv_commd = _path(str);

		if (str == NULL || *str == '\0')
		{
			command_err("");
			exit(127);
		}
		if (execv_commd != NULL)
		{
			if (execve(execv_commd, argv, environ) == -1)
			{
				perror("Error");
			}
			free(execv_commd);
		}
		else
		{
			command_err(str);
		}
	}
}

/**
  * fork_and_exec - fork function
  * @argv: the argument
  * @environ: environment variable
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
