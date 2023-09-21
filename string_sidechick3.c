#include "shell.h"


/**
 * _getenv - gets environment variable (env)
 * @name: env name
 * Return: env variable value
 */
char *_getenv(const char *name)
{
int i = 0;
char *var_name, *var_value, *val = NULL; /*val = value, var = variable*/

for ( ; environ[i] != NULL; i++)
{
var_name = strtok(environ[i], "=");
var_value = strtok(NULL, "=");
if (strcmp(var_name, name) == 0)
{
val = var_value;
break;
}}

return (val);
}
