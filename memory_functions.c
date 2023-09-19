#include "shell.h"

/**
 * free_s - ...
 * @pp: ...
 *
 * Return: ...
 */
void free_s(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * free_p - ...
 * @ptr: ...
 *
 * Return: ...
 */
int free_p(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
