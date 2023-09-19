#include "shell.h"

/**
 * _printerror - ...
 * @error: ...
 *
 * Return: ...
 */
void _printerror(char *error)
{
	ssize_t num_written;

	num_written = write(2, error, _strlen(error));
	if (num_written == -1)
		perror("write");
}
