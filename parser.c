#include "shell.h"

/**
 * parser - will wor on this
*/
int parser(char *line, char **cmd_argv, char **envp)
{
int token_counter = 0, status;
char *token = strtok(line, "\t\n ");
pid_t child_pid;
while (token != NULL && token_counter < MAX_ARGS)
{
cmd_argv[token_counter] = token;
token_counter++;
token = strtok(NULL, "\t\n ");
}
cmd_argv[token_counter] = NULL;

if (token_counter > 0)
{
child_pid = fork();
if (child_pid == -1)
{
perror("Failed to fork, will rather spoon (OMG Zee that's such a lame joke 😒)");
return (EXIT_FAILURE);
}
else if (child_pid == 0) /*child process successfully created*/
{
if (execve(cmd_argv[0], cmd_argv, envp) == -1)
{
perror("failed to execute, guillotine too weak(seriously Zee, stopppp)");
exit(EXIT_FAILURE);
}
}
else /*parent process*/
wait(&status); /*as per considerate elder, wait for the child to finish*/
}
return (EXIT_SUCCESS);

}
