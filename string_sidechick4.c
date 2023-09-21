
#include "shell.h"

/**
 * _strtok - string toknizer
 * @str: string to be parsed into tokens
 * @delim: breaking characters within str
 * Return: a new token after each call
 */
char *_strtok(char *str, const char *delim)
{
return (strtok(str, delim));
}

/**
 * _atoi - really don't know why people refer to this as atoi
 * I mean, what does the a translate to? anyhoo, this is my
 * local version of the atoi
 * @str: The string to be converted, input by user
 * Return: The converted integer,
 * or -1 on conversion error.
 */
int _atoi(char *str)
{
size_t n = 0, i = 0;
char ptive;

while (str[i])
{
if (!((str[i] >= '0') && (str[i] <= '9')))
return (-1);

if (((str[i] >= '0') && (str[i] <= '9')))
n = (n * 10) + (str[i] - '0');
else if (str[i] == '+')
ptive++;
i++;
}

return (n);
}

/**
 * itos - you know, deep down, what this does....you just want to
 * judge me by my definitions....move on, I am not to be shamed 😂😂
 * @n: and this one too 😂😂
 * @str: pointer to resulting string
 */
void itos(int n, char *str)
{
int temp, i = 0;

if (n == 0)
str[i++] = '0';

temp = n;
while (temp > 0)
temp /= 10, i++;

temp = n;
while (i > 0)
{
str[--i] = temp % 10 + '0';
temp /= 10;
}
str[i] = '\0';
}

/**
 * txtTOarr - yeah umn, my name is pretty much explanatory, no?
 * @text: text read from wherever
 * Return: pointer to array of converted text
 */
char **txtTOarr(char *text)
{
char *token, *cmd, **cmd_lines = NULL; /*cmd = command*/
int i = 0;
size_t count = 0;

count = charCounter(text, '\n');
cmd_lines = (char **)malloc((count + 1) * sizeof(char *));
token = strtok(text, "\n");
cmd = _strdup(token);
cmd_lines[i++] = cmd;
while (token != NULL)
{
token = _strtok(NULL, "\n");
if (token != NULL)
{
cmd = _strdup(token);
cmd_lines[i++] = cmd;
}}

free(text);
cmd_lines[i] = NULL;
return (cmd_lines);
}
