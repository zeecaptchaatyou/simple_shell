#include "shell.h"

/**
 * _getenv - ...
 * @args: ...
 * @command: ...
 *
 * Return: ...
 */
int _getenv(char *command, char **args)
{
	char **env;

	if (_strcmp(command, "env") == 0)
	{
		for (env = environ; *env != NULL; env++)
			_puts(*env);

		if (args != NULL)
		{
			for (i = 0; args[i] != NULL; i++)
				free(args[i]);
			free(args);
		}

		return (0);
	}

	return (1);
}
