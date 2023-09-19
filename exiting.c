#include "shell.h"

/**
 * exiting - ...
 * @command: ...
 * @status: ...
 * @args: ...
 *
 * Return: ...
 */
void exiting(char *command, int status, char **args)
{
	char *endptr;
	int i = 0;

	if (_strcmp(command, "exit") == 0)
	{
		free(command);

		if (args != NULL && args[1] != NULL)
		{
			status = _atoi(args[1]);

			if (status < 0)
				write(STDERR_FILENO, "./hsh: 1: exit: Illegal number: ", 32);
			if (status < 0)
				status = 0;
			else
				status = status;

			while (args[i] != NULL)
			{
				free(args[i]);
				i++;
			}
			free(args);
		}
		else
		{
			free(args[0]);
			free(args);
		}

		exit(status);
	}
}
