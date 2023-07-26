#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

void execmd(char **argv, char **environ);
char *_path(char *argv);
void fork_and_exec(char **argv, char **environ);
void free_argv(char **argv);
/*error handleer*/
void command_err(const char *str);

/** string function **/
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strlen(char *str);
char *_strdup(char *str);
int _putchar(char c);
int _strchr(char *str, char ch);
#endif
