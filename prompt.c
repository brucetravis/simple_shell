#include "shell.h"

#define MAX_COMMAND_LENGTH 1024
#define PROMPT "#cisfun$ "

int main(void)
{
char command[MAX_COMMAND_LENGTH];
pid_t pid;

while (1)
{
printf("%s", PROMPT);

if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
{
printf("\n");
break;
}

command[strcspn(command, "\n")] = '\0';

pid = fork();
if (pid < 0)
{
perror("Fork failed");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (execlp(command, command, NULL) == -1)
{
fprintf(stderr, "%s: Command not found\n", command);
exit(EXIT_FAILURE);
}
}
else
{
int status;
waitpid(pid, &status, 0);
}
}

return (EXIT_SUCCESS);
}
