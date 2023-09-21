#include "shell.h"

/**
 * main - a shell program
 * @argc: argument counter
 * @argv: array of argument vectors
 * @env: an array of environmental variables (envp)
 * Return: will be back to update this
*/
int main(int argc, char *argv[], char *env[])
{
int *status, count = 0, non_interactive = 1, s = 0, op_mode;
char *cmd, **cmd_lists, **cmd_arr = NULL;
list_paths *current;
status = &s;
op_mode = mode_checker(argc);

if (op_mode != INTERACTIVE_MODE)/*checking the file after the command*/
cmd_lists = scan_command_files(op_mode, argv[1], argv[0]);
current = paths_to_linkedlist();/*turning the path current to a linked */
while (non_interactive && ++count)
{
if (op_mode == NON_INTERACTIVE_MODE || op_mode == NON_INTERACTIVE_PIPE)
{
if (cmd_lists[count - 1])
cmd = cmd_lists[count - 1];
else
{ free(cmd_lists);
break;
}} else if (op_mode == INTERACTIVE_MODE)
cmd = scan_userInput(current); /*prompt user&get command*/
if (!cmd)
continue;
cmd_arr = line_parser(cmd, *status);
if (!cmd_arr)
{
free(cmd);
continue; }
if (dir_check(cmd_arr[0], argv, count, cmd_arr, status, cmd) == 0)
continue;
if (builtin_handler(cmd, cmd_arr, current, argv[0],
count, status, NULL, cmd_lists, argv) != 0)
non_builtin_cmd_handler(cmd_arr, env, status, count, current, argv);
free_all(cmd, cmd_arr); }
free_list(current);
exit(*status); }

/*
 * when I'm done with this, I'll try myself to 10 episodes of family guy
 * and finally play with Node.js 🥹🥹🥹🥹.....fourteen days!
 */
