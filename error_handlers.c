#include "shell.h"

/**
 * print_error - displays error message to stderr
 * @shell_name: program name
 * @count: cmd count
 * @cmd_arr: The command or argument causing the error.
 * @error_type: The type of error.
 */

void print_error(char *shell_name, int count,
char *cmd_arr, int error_type)
{
char *str_counter;

str_counter = numTOchar(count);

write(STDERR_FILENO, shell_name, _strlen(shell_name));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, str_counter, _strlen(str_counter));
write(STDERR_FILENO, ": ", 2);

if (error_type == EXIT_ERROR)
{
write(STDERR_FILENO, "Illegal number: ", 16);
write(STDERR_FILENO, cmd_arr, _strlen(cmd_arr));
write(STDERR_FILENO, "\n", 1);
}
else if (error_type == NOT_FOUND)
write(STDERR_FILENO, "not found\n", 10);
else if (error_type == PERMISSION_DENIED)
write(STDERR_FILENO, "Permission denied\n", 18);

free(str_counter);
}
