#include "shell.h"

/**
  * access_checker - checks the access status of a cmd in the cmd line
  * @current: current path turned into linked lists.
  * @cmd:  line from user entered by getline and path list.
  * Return: full path of the command if:
  * it is found be able to access and execute it.
  * else if it fails return NULL.
  */
char *access_checker(char *cmd, list_paths *current)
{
char *full_path;
int found_path, len, cmd_len, current_path_len;

if (current == NULL)
return (NULL);

while (current)
{
current_path_len = _strlen(current->path);
cmd_len = _strlen(cmd);
len = (current_path_len + cmd_len + 2);

full_path = (char *)malloc(len *sizeof(char));
_strcpy(full_path, current->path);
_strcat(full_path, "/"), _strcat(full_path, cmd);
found_path = 0;
if (access(full_path, X_OK) == 0)
{
found_path = 1;
break;
}
else
free(full_path);
current = current->next;
}
if (found_path)
return (full_path);

else
return (NULL);
}
/**
 * input_file_checker - checks if its argument file exists and readable
 * @file: file to be checked
 *Return: ptr to file
 */
char *input_file_checker(char *file)
{
char *cmd;
cmd = _strdup(file);

	return (cmd);
}

/**
 * mode_checker - a function that checks the mode of my terminal
 * @argc: arguments' count
 * Return: 1 in case of interactive mode,
 *			0 in case of non-interactive mode,
 *			-1 in case of error.
*/
int mode_checker(int argc)
{
struct stat stdin_stat;

fstat(STDIN_FILENO, &stdin_stat);
if (argc == 1 && isatty(STDIN_FILENO))
return (INTERACTIVE_MODE);
if ((!isatty(STDIN_FILENO) && argc == 1))
return (NON_INTERACTIVE_PIPE);
if ((argc >= 1))
return (NON_INTERACTIVE_MODE);
return (ERROR);
}
