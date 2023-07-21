#include "shell.h"

/**
  * function - that get the path command
  * @path: the command
  * Return: return NULL
  */

char *_path(char *str)
{
	char *token_path, *path, *path_dup, *file_path;
	int str_length, dir_length;
	struct stat buffer;
	path = getenv("PATH");

	if (path)
	{
		path_dup = _strdup(path);
		str_length = _strlen(str);
		token_path = strtok(path_dup, ":");

		while (token_path != NULL)
		{
			dir_length = _strlen(token_path);
			str_length = _strlen(str);
			file_path = malloc(str_length + dir_length + 2);
			_strcpy(file_path, token_path);
			_strcat(file_path, "/");
			_strcat(file_path, str);
			_strcat(file_path, "\0");

			if (stat(file_path, &buffer) == 0)
			{
				free(path_dup);
				return (file_path);
			}
			else
			{
				free(file_path);
				token_path = strtok(NULL, ":");
			}
		}
		free(path_dup);
		if (stat(file_path, &buffer) == 0)
		{
			return (str);
		}
		return (NULL);
	}
	return (NULL);
}
