#include "shell.h"

#define MAX_COMMAND_LENGTH 1024
#define PROMPT "#cisfun$ "

/**
 * main - handling arguments
 * @argc: argument count.
 * @argv: argumment vector
 *
 */

int main(void)
{
char command[MAX_COMMAND_LENGTH];
char *args[MAX_COMMAND_LENGTH];
int i;
pid_t pid;
int status;

while (1)
{
printf("%s", PROMPT);
        
if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
{
printf("\n");
break;
}

command[strcspn(command, "\n")] = '\0';

char *token;
i = 0;

token = strtok(command, " ");
while (token != NULL)
{
args[i++] = token;
token = strtok(NULL, " ");
}
args[i] = NULL;

pid = fork();
if (pid < 0)
{
perror("Fork failed");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
fprintf(stderr, "%s: Command not found\n", args[0]);
exit(EXIT_FAILURE);
}
}
else
{
waitpid(pid, &status, 0);
}
}

return (EXIT_SUCCESS);
}
