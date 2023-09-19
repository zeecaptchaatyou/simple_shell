#include "shell.h"

/**
 * _child - ...
 * @args: ...
 * @token: ...
 *
 * Return: ...
 */
int _child(char *token, char **args)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return (1);
	}

	if (pid == 0)
	{
		if (execve(token, args, environ) == -1)
		{
			perror("execve");
			exit(1);
		}
	}
	else
	{
		if (waitpid(pid, &status. 0) == -1)
		{
			perror("waitpid");
			return (1);
		}

		if (WIFEXITED(status))
			return (WEXITSTATUS(status));

		return (1);
	}

	return (0);
}
