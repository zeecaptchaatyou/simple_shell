#include"shell.h"

/**
 * exit_handler - checks if the command is an "exit" command and handles it.
 * @command: The original command entered by the user.
 * @command_array: An array of strings containing the command and its arguments
 * @current: A pointer to a list_paths struct representing the current path.
 * @shell_name: The name of the shell program.
 * @count: cmd counter
 * @status: A pointer to an integer variable representing the status.
 * @command_lines:.
 * @env: environmental variable
 */

void exit_handler(char *command, char **command_array, list_paths *current,
char *shell_name, int count, int *status,
list_paths *env, char **command_lines)
{
	int exit_num;

	if (_strcmp(command_array[0], "exit") == 0)
	{
		if (command_array[1] == NULL)
		{
			free_whole(command_lines, count, env,
			current, command, command_array);
			exit(*status);
		}
		else if (command_array[1] != NULL)
		{
			if (_strlen(command_array[1]) <= 9)
			{
				exit_num = _atoi(command_array[1]);
				if (exit_num != -1)
				{
					free_whole(command_lines, count, env,
					current, command, command_array);
					exit(exit_num);
				}
				else
				{
					*status = EXIT_ERROR;
					print_error(shell_name, count, command_array[1], EXIT_ERROR);
				}
			}
			else
			{
				*status = EXIT_ERROR;
				print_error(shell_name, count, command_array[1], EXIT_ERROR);
			}
		}
	}
}
/**
 * free_whole - free whole
 * @command: The original command entered by the user.
 * @command_array: An array of strings containing the command and its arguments
 * @current: A pointer to a list_paths struct representing the current path.
 * @count: The command count.
 * @command_lines:.
 * @env:.
 * Return: Nothing
*/
void free_whole(char **command_lines, int count, list_paths *env,
		list_paths *current, char *command, char **command_array)
{
	if (command_lines)
	{
		free(command_lines[count]);
		if (command_lines)
			free(command_lines);
	}
	free_list(env);
	free_list(current);
	free_all(command, command_array);
}


/**
* free_all - Free allocated memory
* @command: Pointer to the command string
* @command_array: Pointer to the array of command and its arguments
* This function frees the memory allocated.
* command and its arguments.
*/
void free_all(char *command, char **command_array)
{
	free(command);
	free_array(command_array);
}

/**
 * free_array - Frees memory allocated for an array of strings.
 * @argv: The array of strings to be freed.
 */
void free_array(char **argv)
{
char **current_character;

	if (argv == NULL)
	return;

	current_character = argv;

	while (*current_character != NULL)
	{
		free(*current_character);
		current_character++;
	}


	free(argv);
}
/**
* free_vector - Frees the memory allocated for a vector of strings.
* @vector: The vector to free.
*/

void free_vector(char **vector)
{
	int i = 0;

	if (vector == NULL)
	{
		return;
	}
	for (i = 0; vector[i] != NULL; i++)
	{
		free(vector[i]);
	}
	free(vector);

}
