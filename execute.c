#include "shell.h"

/**
 * command_executer - (in Stewie's voice)yeah, yeah, what do you think I do?
 * @path: path to command to be executed
 * @av: an argv type of array....this one contains parsed input
 * @env: environmental variables.....they're THE SHELL
 * @status: sets status for every proccess
 */
void command_executer(char *path, char **av, char **env, int *status)
{
pid_t parent_id;

parent_id = fork();
if (parent_id < 0)
{
perror("Failed to fork");
exit(EXIT_FAILURE);
}

if (parent_id == 0)
{
execve(path, av, env);
perror("Failed to execute");
exit(EXIT_FAILURE);
}
else if (parent_id > 0)
{
waitpid(parent_id, status, WUNTRACED);
*status  = WEXITSTATUS(*status); }}
