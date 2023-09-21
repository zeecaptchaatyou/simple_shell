#include"shell.h"


/**
 * flags_handler - handles flags usage ad bitwise thingys
 * @token: yeah, token
 * @cmd: command
 * @arg_v: array of parsed user input
 * @status: represents process status
 * Return: cmde
*/
char *flags_handler(char *token, char *cmd,
char **arg_v, int status)
{
char *var, *cmde, *copied_line;

copied_line = cmd;
if (token == NULL)
{
free(arg_v);
free(copied_line);
return (NULL);
}
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

return (cmde);
}
