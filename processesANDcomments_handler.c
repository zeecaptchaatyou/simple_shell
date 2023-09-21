#include "shell.h"


/**
 * get_status - enstrings its argument (omg I don't even know if enstring
 * is a word 😂😂)
 * @n: The status value to convert to a string.
 * Return: string rep of argument n
 */
char *get_status(int n)
{
return (numTOchar(n));
}

/**
 * get_process_id - gets string rep of a pid and returns it
 * Return: pointer to a process id str representation
 */

char *get_process_id()
{
return (numTOchar(getpid()));
}

/**
 * comments_handler - ya'll know what the preprocessor does on our c
 * files, yeahhhhh.....thisbaby right here removes comments too!
 * @input: yeah, just input
 */
void comments_handler(char *input)
{
bool quote = false;
int i = 0;
for ( ; input[i]; i++)
{
if (input[i] == '"')
quote = !quote;
else if (input[i] == '#' && !quote)
{
input[i] = '\0';
break;
}
}}
