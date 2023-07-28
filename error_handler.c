#include "shell.h"
/**
  * command_err - function that handles the command errors
  * @str: the command
  * Return: return 127
  */

int command_err(char *str)
{
	char err_msg[] = "./hsh: 1: ";
	char not_found_msg[] = ": not found\n";

	write(2, err_msg, sizeof(err_msg) - 1);
	write(2, str, _strlen(str));
	write(2, not_found_msg, sizeof(not_found_msg) - 1);
	return (127);
}

/**
 * _strcmp - function that compare strings
 * @s1: first string
 * @s2: second string
 * Return: return 0
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}

	return (0);
}


int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

    for (i = 0; i < n; i++) {
        if (str1[i] != str2[i]) {
            return (int)(unsigned char)str1[i] - (int)(unsigned char)str2[i];
        }
        if (str1[i] == '\0') {
            break;
        }
    }
    return 0;
}
