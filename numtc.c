#include "shell.h"
/*
 * putn this here because stupid betty keeps raising errors when
 * it's in other files when it doesn't even exceed five functions, ugh!
 * btw, this file's name is short for "number to char"
 */
/**
 * numTOchar - Converts an integer to a string.
 * @num: first argument,
 * Return: str version of the number
 */

char *numTOchar(int num)
{
int count = 0, temp = num;
char *num_cpy; /*num_cpy = number copied*/

if (num == 0)
count = 1;
else
{
while (temp != 0)
temp /= 10, count++;
}

num_cpy = (char *)malloc(sizeof(char) * (count + 1));
if (!num_cpy)
{
perror("malloc error");
return (NULL);
}

num_cpy[count] = '\0';

while (count != 0)
{
count--;
num_cpy[count] = '0' + num % 10;
num /= 10;
}

return (num_cpy);
}
