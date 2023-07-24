#include "shell.h"

/**
  * execmd - function that excute
  * @argv: the argument varible
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

/**
  * fork_and_exec - fork function
  * @argv: the argument
 */

void fork_and_exec(char **argv)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		execmd(argv);
		exit(EXIT_SUCCESS);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			int exit_status = WEXITSTATUS(status);
		printf("Child process exited with status: %d\n", exit_status);
		}
	}
}
