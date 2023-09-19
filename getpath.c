#include "shell.h"

/**
 * _getpath - ...
 * @command: ...
 *
 * Return: ...
 */
char *_getpath(char *command)
{
	char *env, *path, *token, *full_path;
	size_t len;

	env = getenv("PATH");
	if (env == NULL)
		return (NULL);
	path = _strdup(env);
	if (path == NULL)
	{
		perror("Memory allocation error");
		return (NULL);
	}
	token = strtok(path, ":");
	while (token != NULL)
	{
		len = _strlen(token) + 1 + _strlen(command) + 1;
		full_path = malloc(len);
		if (full_path == NULL)
		{
			perror("Memory allocation error");
			free(path);
			return (NULL);
		}
		_strcpy(full_path, token);
		_strcat(full_path, "/");
		_strcat(full_path, command);
		if (stat(full_path, &sb) == 0)
		{
			free(path);
			return (full_path);
		}
		free(full_path);
		token = strttok(NULL, ":");
	}
	free(path);
	return (NULL);
}
