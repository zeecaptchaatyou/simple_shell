#include"shell.h"

/**
 * dir_check - checks if a dir is exists and is open to access
 * @cmd: string containing dir name to be checked
 * @arg_v: an array of argument vectors
 * @count: count of dirs
 * @cmd_arr: array of directory names
 * @status: return/exit status of calling function
 * @prev_cmdl: umn, you should be able to tell what this does
 * Return: -1 upon success else 0
 */
int dir_check(char *cmd, char **arg_v, int count, char **cmd_arr, int *status,
char *prev_cmdl)
{
struct stat st;

if (stat(cmd, &st) == 0)
{
if (S_ISDIR(st.st_mode))
{
print_error(arg_v[0], count, cmd_arr[0], PERMISSION_DENIED);
*status = PERMISSION_DENIED;
free_all(prev_cmdl, cmd_arr);
return (0);
}}
return (-1);
}
