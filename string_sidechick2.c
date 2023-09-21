#include "shell.h"


/**
 * _strdup - duplicates its argument string
 * @str: string to tbe duplicated
 * Return: pointer to new duplicate if malloc is successful
 */
char *_strdup(char *str)
{
int len = _strlen(str);
char *arr;

if (str == NULL)
return (NULL);

arr = (char *)malloc((sizeof(char) * len) + 1);
if (arr == NULL)
return (NULL);
arr[len] = '\0';
while (len--)
arr[len] = str[len];
return (arr);
}

/**
 * _strcmp - compares its two argument strings.
 * @str1: Pointer to the first string to be compared.
 * @str2: Pointer to the second string to be compared.
 * Return: 0, < 0 or > 0
*/
int _strcmp(char *str1, char *str2)
{
while (*str1 && *str2 && *str1 == *str2)
{
if (*str1 != *str2)
return ((int)*str1 - (int)*str2);

str1++, str2++;
}

return ((int)*str1 - (int)*str2); /*return a typecasted value*/
}

/**
* _strlen - returns the length of a string
* @s: a pointer to the string
*
* This function takes a pointer to a
* string and counts the number of characters
* in the string using a loop. It returns the length of
* the string as an integer.
*
* Return: the length of the string as an integer.
*/
int _strlen(char *s)
{
int len = 0;

while (*s != '\0')
len++, s++;

return (len);
}

/**
 * _strcpy - copies a string
 * @dest: destination string
 * @src: source string
 * Return: ptr to dest
 */
char *_strcpy(char *dest, char *src)
{
int i = 0;

for ( ; src[i] != '\0'; i++)
dest[i] = src[i];

/*some null termination right here*/
dest[i] = '\0';

return (dest);
}


/**
 * _strcat - concatenates its two argument strings.
 * @dest: destination buffer, buffer to hold result
 * @src: source string
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
int len = _strlen(dest), i = 0;

len = _strlen(dest);

for ( ; src[i] != '\0'; i++)
dest[len + i] = src[i];

dest[len + i] = '\0';
return (dest);
}
