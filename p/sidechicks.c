#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{ return (write(1, &c, 1)); }

/**
 * _strlen - returns the length of a string
 * @s: string to be measured
 * Return: length of s
*/
int _strlen(char *s)
{
int i = 0;
while (s[i])
i++;
return (i);
}

/**
 * _strcmp - 
 * @str:
 * @ch:
 * Return:
*/
int _strcmp(const char *str1, const char *str2)
{
while (*str1 != '\0' && *str2 != '\0')
{
if (*str1 != *str2)
return (*str1 - *str2);

str1++, str2++;
}

return (*str1 - *str2);
}


/**
 * _strchr - returns the pointer to the first occurrence
 * of the character c within the string s
*/
char *_strchr(const char *str, int ch)
{
while (*str != '\0')
{
if (*str == ch)
return ((char *)str); // Found the character
str++;
}

return (NULL); // Character not found
}

/**
 * _strncmp -
*/
int _strncmp(const char *str1, const char *str2, size_t n)
{
    while (n > 0 && *str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return (*str1 - *str2);
        }
        str1++;
        str2++;
        n--;
    }

    // If n becomes zero or both strings reach the end, they are considered equal
    if (n == 0 || (*str1 == '\0' && *str2 == '\0')) {
        return 0;
    }

    // If str1 is shorter than str2 and n is not zero, str1 is considered less
    if (*str1 == '\0') {
        return -1;
    }

    // If str2 is shorter than str1 and n is not zero, str1 is considered greater
    return 1;
}

/**
 * _strspn - 
 * @s: 
 * @accept:
 * Return:
*/
size_t _strspn(const char *s, const char *accept)
{
size_t count = 0;
int found = 1;
const char *a ;

while (*s)
{
a = accept;
found = 0;

while (*a)
{
if (*s == *a)
{
found = 1;
break;
}
a++;
}

if (!found)
break;

count++, s++;
}

return (count);
}


/**
 * strcspn_custom - Calculates the length of the initial segment of str that
 *                 consists of characters not in the delimiters string.
 * @str: The string to be searched.
 * @delimiters: A string containing delimiter characters.
 * 
 * Return: The length of the initial segment of str that consists of characters
 * not in the delimiters string.
 */
size_t _strcspn(const char *str, const char *delimiters)
{
size_t len = 0;
const char *p;

/* Loop through the string until a delimiter character is found */
for (p = str; *p != '\0'; p++)
{
if (_strchr(delimiters, *p) != NULL)
break;

len++;
}

return (len);
}

/**
 * _strtok - Tokenizes a string based on specified delimiters.
 * @str_ptr: A pointer to the input string. Will be modified during
 * tokenization.
 * @delimiters: A string containing delimiter characters.
 * Return: A pointer to the next token in the input string,
 * or NULL if no more tokens are found.
 */
char *_strtok(char *str_ptr, const char *delimiters)
{
static char *token_start, *token_end;

/* Check if the input string pointer is NULL or pointing to an empty string */
if (str_ptr == NULL || *str_ptr == '\0')
return (NULL);


/* Find the start of the token by skipping leading delimiters */
*str_ptr += _strspn(*str_ptr, delimiters);

/* Check if we've reached the end of the string */

/* Find the end of the token */
token_start = *str_ptr;
token_end = token_start + _strcspn(token_start, delimiters);

/* Null-terminate the token and update the input string pointer */
if (*token_end != '\0')
{
*token_end = '\0';
*str_ptr = token_end + 1;
}
else
*str_ptr = NULL;

return (token_start);
}
