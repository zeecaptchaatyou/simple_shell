#include "shell.h"

/**
 * prompt - ...
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, ";) ", 3);
}
