#include"shell.h"

/**
* non_builtin_cmd_handler - Handles non-builtin commands
* @cmd_arr: obviously.....
* @env: env
* @status: Pointer to the variable 'status'
* @count: count of commands executed successfully
* @current: Pointer to the list_paths structure
* @argv: array of parsed commands
*/
void non_builtin_cmd_handler(char **cmd_arr, char *env[], int *status,
int count, list_paths *current, char *argv[])
{
char *new_path;

if (access(cmd_arr[0], X_OK) == 0)
command_executer(cmd_arr[0], cmd_arr, env, status);
else
{
new_path = access_checker(cmd_arr[0], current);
if (new_path)
{
command_executer(new_path, cmd_arr, env, status);
free(new_path);
}
else
{
print_error(argv[0], count, cmd_arr[0], NOT_FOUND);
*status = NOT_FOUND; }}}
