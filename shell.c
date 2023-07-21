#include "shell.h"

/**
  * main - shell main function
  * argc: argument count
  * argv: arguments variable
  * Return: return 0
  */


int main(int ac, char **argv)
{
char *lineptr = NULL, *lineptr_dup = NULL, *token;
	size_t n = 0;
	ssize_t linelen;
	int token_len = 0, i;
	const char *delim = " \n";

	(void)ac;
	while (1)
	{
		printf("$shell@: ");
		linelen = getline(&lineptr, &n, stdin);
		if (linelen == - 1)
		{
			printf("[Disconnected...]\n");
			return (-1);
		}
		lineptr_dup = malloc(sizeof(char) * linelen);
		if (lineptr_dup == NULL)
		{
			perror("tsh: memory allocatiotion error");
			return (-1);
		}
		_strcpy(lineptr_dup, lineptr);

		token = strtok(lineptr, delim);
		while (token != NULL)
		{
			token_len++;
			token = strtok(NULL, delim);
		}
		token_len++;
		argv = malloc(sizeof(char *) * token_len);
		token = strtok(lineptr_dup, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * _strlen(token));
			_strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		execmd(argv);
	}
	free(lineptr_dup);
	free(lineptr);
	return (0);
}
