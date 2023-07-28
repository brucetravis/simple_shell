#include "shell.h"

#define BUFFER_SIZE 1024

char *custom_getline(void)
{
    static char buffer[BUFFER_SIZE];
    static int position = 0;
    static int bytesRead = 0;

    char *line = NULL;
    int lineSize = 0;
    char c;

    while (1)
    {

        if (position >= bytesRead)
        {
            bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE);
            position = 0;


            if (bytesRead <= 0)
            {

                if (lineSize > 0)
                {
                    line[lineSize] = '\0';
                    return (line);
                }

                return (NULL);
            }
        }

	c = buffer[position++];

        if (c == '\n')
        {

            line[lineSize] = '\0';
            return (line);
        }


        if (lineSize == 0) {
            line = (char *)malloc(BUFFER_SIZE);
            if (line == NULL) {
                perror("malloc");
                exit(EXIT_FAILURE);
            }
        } else if (lineSize % BUFFER_SIZE == 0) {
            char *newLine = (char *)realloc(line, lineSize + BUFFER_SIZE);
            if (newLine == NULL) {
                perror("realloc");
                free(line);
                exit(EXIT_FAILURE);
            }
            line = newLine;
        }

        line[lineSize++] = c;
    }

    return (NULL);
}
