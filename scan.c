#include"shell.h"

/**
 * scan_userInput - uses the getline to scan user input
 * @current: pointer to linked list of directories in the current env path
 * Return: the command scanned
 */
char *scan_userInput(list_paths *current)
{
ssize_t read;
size_t s = 0;
char *command = NULL;

write(STDOUT_FILENO, "($) ", 4);
read = getline(&command, &s, stdin);

/*handling EOF*/
if (read == EOF)
{
/*write new line and free*/
write(STDOUT_FILENO, "\n", 1);
free_list(current);
free(command);
exit(0);
}
/* If the user enters a blank line, return NULL */
if (read == 1 && command[0] == '\n')
{
free(command);
return (NULL);
}

command[read - 1] = '\0';

return (command);
}

/**
 * scan_command_files - Scans command files based on the operation mode.
 * @op_mode: The operation mode.
 * @file_name: The name of the command file.
 * @shell_name: The name of the shell program.
 * Return: The array of command lines read from the file.
 */
char **scan_command_files(int op_mode, char *file_name, char *shell_name)
{
char **cmd_lines;

if (op_mode == NON_INTERACTIVE_PIPE)
{
cmd_lines = noninteractive_pipes_handler();
if (!cmd_lines)
exit(0);
}
else if (op_mode == NON_INTERACTIVE_MODE)
{
cmd_lines = noninteractive_files_handler(file_name, shell_name);
if (!cmd_lines)
exit(0);
}
return (cmd_lines);
}
