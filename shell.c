#include "shell.h"
#define MAX_TOKEN 64
/**
  * main - shell main functions
  * @ac: argument count
  * @argv: arguments variable
  * @environ: envroment variable
  * Return: return 0
  */

int main(int ac, char **argv, char **environ)
{char *lineptr = NULL, *token[MAX_TOKEN], *token_l;
	size_t n = 0;
	ssize_t linelen;
	int token_count;
	const char *delim = " \n";

	(void)ac, (void)argv;
	while (1)
	{
		if (isatty(STDIN_FILENO) != 0)
		{
			write(1, "$ ", 2);
		}
		linelen = getline(&lineptr, &n, stdin);
		if (linelen == -1)
		{
			free(lineptr);
			exit(EXIT_SUCCESS);
		}
		token_count = 0;
		token_l = strtok(lineptr, delim);
		while (token_l != NULL && token_count < MAX_TOKEN - 1)
		{
			token[token_count] = token_l;
			token_count++;
			token_l = strtok(NULL, delim);
		}
		token[token_count] = NULL;
		if (token_count > 0)
		{
			fork_and_exec(token, environ);
		}
	}
	free(lineptr);
	return (0);
}
