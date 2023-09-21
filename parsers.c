#include "shell.h"

/**
 * charCounter - counts the occurrences of c in str
 * @str: first argument,  string to be searched
 * @c: the missing piece of Jumanji...call me Ruby Roundhouse 😌😂.
 * Return: the number of occurrences of @c in @string
 */
unsigned int charCounter(char *str, char c)
{
size_t count = 0;

while (*str)
if (*str++ == c)
count++;

return (count + 1);
}

/**
 * print_env - prints the environment variables (envs).
 * @status: pointer to variable that sets the status
 */
void print_env(int *status)
{
int i;

for (i = 0; environ[i] != NULL; i++)
{
write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
write(STDOUT_FILENO, "\n", 1);
}
/*completion successful*/
*status = 0;
}


/**
 * token_proccessor - Processes a token and returns the corresponding string.
 * @token: The input token to process.
 * @status: An integer representing the status of the command.
 * Return: A dynamically allocated string representing the processed token.
 */
char *token_proccessor(char *token, int status)
{
	char *cmde = NULL, *variable = NULL;


if (_strcmp("$$", token) == 0)
cmde = get_process_id();
else if (_strcmp("$?", token) == 0)
cmde = get_status(status);
else if (token[0] == '$' && token[1] != '\0')
{
variable = _getenv(&token[1]);
cmde = (variable != NULL) ? _strdup(variable) : _strdup("");
}
else
cmde = _strdup(token);
return (cmde);
}


/**
 * line_count - returns number of lines in an array of strings
 * @line: argument
 * Return: yeah, we talked about this
 */
int line_count(char *line)
{
int i = 0;

while (*line != '\0')
i++, line++;

return (i);
}

/**
 * line_parser - parses a long string into an argv like array
 * @cmd: the string to convert
 * @status: an integer representing the status of the command
 * Return: a pointer to a char array.
 */
char **line_parser(char *cmd, int status)
{
char *copied_line, *token, **arg_v, *var, *cmde;
int i = 0, charCount;

if (cmd[0] == '\0')
return (NULL);

copied_line = _strdup(cmd);
if (copied_line == NULL)
return (NULL);

charCount = char_count(copied_line, ' ');
arg_v = (char **)malloc((charCount + 1) * sizeof(char *));

token = _strtok(copied_line, TOK_D);
cmde = flags_handler(token, cmd, arg_v, status);
arg_v[i++] = cmde;
while (token != NULL)
{
token = _strtok(NULL, TOK_D);
if (token != NULL)
{
if (_strcmp("$$", token) == 0)
cmde = get_process_id();
else if (_strcmp("$?", token) == 0)
cmde = get_status(status);
else if ((token[0] == '$') && (token[1]))
{
var = _getenv(&token[1]);
if (var)
cmde = _strdup(var);
else
cmde = _strdup("");
}
else
cmde = _strdup(token);
arg_v[i++] = cmde; }}
arg_v[i] = NULL;
free(copied_line);
return (arg_v);
}
