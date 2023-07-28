#include "shell.h"


#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64
#define PROMPT "#cisfun$ "

int read_command(char *command, char *args[])
{
    int i = 0;
    char c;
    int argCount = 0;
    char *token;

    while ((c = getchar()) != '\n' && c != EOF)
    {
        command[i++] = c;
    }
    command[i] = '\0';

    if (c == EOF && i == 0)
    {
        return (0);
    }

    token = strtok(command, " ");
    while (token != NULL && argCount < MAX_ARGUMENTS - 1) {
        args[argCount] = token;
        token = strtok(NULL, " ");
        argCount++;
    }
    args[argCount] = NULL;

    return (1);
}
