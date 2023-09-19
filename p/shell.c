#include "shell.h"

/**
 * main - just a simple shell..
 * @argc: you know what it is
 * @argv: do I even have to talk about this?
 * Return: 0
*/
int main(int argc, char **argv, char **envp)
{
char *line = NULL;
size_t line_len = 0;
int chars_read;
char *cmd_argv;
if (envp[0] == NULL)
return (0);

while (1)
{
_putchar(36);

chars_read = getline(&line, &line_len, stdin);

if (chars_read == -1)
{
perror("omo");
break;
}


free(line);
line = NULL;
}

return (0);
}
