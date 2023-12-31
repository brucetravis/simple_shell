#include "shell.h"

/**
 * _strcpy - Entry points
 * @dest: first pointer
 * @src: second pointer
 * Return: return dest
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;
	int x = 0;

	while (*(src + i) != '\0')
	{
		i++;
	}
	for (; x < i; x++)
	{
		dest[x] = src[x];
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strcat - Entry point
 * @dest: first pointer
 * @src: second pointer
 * Return: return dest
 */

char *_strcat(char *dest, char *src)
{
	int i;
	int lentOfDest = 0;
	int lentOfSrc = 0;

	for (i = 0; dest[i] != '\0'; i++)
	{
		lentOfDest++;
	}

	for (i = 0; src[i] != '\0'; i++)
	{
		lentOfSrc++;
	}
	for (i = 0; i <= lentOfSrc; i++)
	{
		dest[lentOfDest + i] = src[i];
	}

	return (dest);
}

/**
  * _strdup - function that allocate memory to duplicate string
  * @str: the string
  * Return: return a pointer
  */
char *_strdup(char *str)
{
	char *dup;
	int i, lenght;

	if (str == NULL)
	{
		return (NULL);
	}
	lenght = _strlen(str);

	dup = (char *)malloc((sizeof(char) * lenght) + 1);
	if (dup == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < lenght; i++)
	{
		dup[i] = str[i];
	}
	dup[lenght] = '\0';

	return (dup);
}

/**
  * _strlen - funtion that return the length of a string
  * @str: the string
  * Return: return i
  */
int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}

/**
  * _strchr - character marched to the function
  * @str: the string
  * @ch: the character
  * Return: return 0
  */

int _strchr(char *str, char ch)
{
	while (*str)
	{
		if (*str == ch)
		{
			return (1);
		}
		str++;
	}
	return (0);
}
