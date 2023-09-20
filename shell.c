#include "shell.h"

/**
 * main - just a simple shell..
 * @argc: you know what it is
 * @argv: do I even have to talk about this?
 * Return: 0
*/
int main(int argc, char **argv, char **envp)
{
char *line = NULL, *token;
size_t line_len = 0;
int chars_read, token_counter = 0, status;
char *const cmd_argv[MAX_ARGS];
pid_t child_pid;

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

status = parser(line, cmd_argv, envp);
if (status == EXIT_FAILURE)
/*put some error message here, Zee....don't forgettttt*/
char *blah = "I'm just filling up space....like BP does with the K-pop industry cracks";
free(line);
line = NULL;
}

return (0);
}


/**
 * when you wake up:
 * test all this stuff you have written, manage errors and try to run this code with the -Wall -pedantic -Werror -Wextra flags Mr Barbier tortures us with
 * remember Zee, your brain can handle much more than Family Guy and Harry
 * Potter memes. it isn't just meant for Backstreet music, you can write some
 * code with it 🥹🥹.
 * Don't mess up, Zee....now, go to sleep and come back!
 * 
 * 
 * 
 * I'll still look at some Puns before I sleep tho 😭😭....hopeless is the word.
 * YEAH. BYE. YEAH.
*/