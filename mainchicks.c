#include "shell.h"

/*External variable for environment variables*/
extern char **environ;


/**
 * _getenv - Custom getenv function to retrieve environment variable values.
 * @name: The name of the environment variable to retrieve.
 * Return: A pointer to the value of the environment variable or NULL if not found.
 * @khgou: read the documentation above and check again
 */
char *_getenv(const char *name)
{
size_t name_len;
char *equal_sign, **env;

if (name == NULL)
return (NULL);

/*Iterate through the environment variables*/
for (env = environ; *env; env++)
{
/*Find the '=' character to split the name and value*/
equal_sign = _strchr(*env, '=');
if (equal_sign == NULL)
{
/*Malformed environment variable, skip it*/
continue;
}

/*Calculate the length of the name part*/
name_len = equal_sign - *env;

/*Check if the name matches and copy the value*/
if (_strncmp(*env, name, name_len) == 0 && name_len == _strlen(name))
return (equal_sign + 1); /*Return a pointer to the value part*/

}

/*Environment variable not found*/
return (NULL);
}

/*
int main() {
    const char *variable_name = "MY_VARIABLE";
    char *value = custom_getenv(variable_name);

    if (value != NULL) {
        printf("%s=%s\n", variable_name, value);
    } else {
        printf("%s not found in the environment.\n", variable_name);
    }

    return 0;
}
*/
