#include "shell.h"
/**
  * _path - function that handles path
  * @argv: the command
  * Return: return NULL
  */

char *_path(char *argv)
{char *path_way = getenv("PATH"), *path_dir;
	char *path_dup = _strdup(path_way);
	char path_buf[256];

	if (_strchr(argv, '/'))
	{
		if (access(argv, X_OK) == 0)
		{
			return (_strdup(argv));
		}
		else
			return (NULL);
	}
	else
	{
	if (path_dup == NULL)
	{
		perror("Memory failed");
		exit(EXIT_FAILURE);
	}
	path_dir = strtok(path_dup, ":");
	while (path_dir)
	{
		_strcpy(path_buf, path_dir);
		_strcat(path_buf, "/");
		_strcat(path_buf, argv);
		if (access(path_buf, X_OK) == 0)
		{
			free(path_dup);
			return (_strdup(path_buf));
		}
		path_dir = strtok(NULL, ":");
	}
	free(path_dir);
	return (NULL);
	}
}
