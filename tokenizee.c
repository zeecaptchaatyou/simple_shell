#include "shell.h"

/**
 * tokenizee - ...
 * @command: ...
 * @delim: ...
 *
 * Return: ..
 */
char **tokenizee(char *command, char *delim)
{
	char **store_args = malloc(sizeof(char *) * MAX_TOKENS);
	int i = 0;
	char *token, *temp;
	char *mem_error = "Memory allocation error";
	char *token_error, limit_char, *newline = ")\n";

	if (!store_args)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	token = strtok(command, delim);
	while (token != NULL)
	{
		if (i >= MAX_TOKENS - 1)
		{
			token_error = "Too many tokens (limit: ";
			limit_char = MAX_TOKENS - 1 + '0';

			write(STDERR_FILENO, token_error, _strlen(token_error));
			write(STDERR_FILENO, &limit_char, 1);
			write(STDERR_FILENO, newline, _strlen(newline));
			break;
		}
		if (i == 0 && token[0] != '.' && _strcmp(token, "exit") != 0)
		{
			if (token[0] != '/')
			{
				temp = _getpath(token);
				write(STDERR_FILENO, path_error, _strlen(path_error));
				free(store_args);
				return (NULL);
			}
			store_args[i] = temp;
		}
		else
			store_args[i] = strdup(token);
		if (!store_args[i])
		{
			write(STDERR_FILENO, mem_error, _strlen(mem_error));
			free(store_args);
			exit(EXIT_FAILURE);
		}
		i++;
		token = strtok(NULL, delim);
	}
	store_args[i] = NULL;
	return (store_args);
}
