#include "shell.h"

/**
 * paths_to_linkedlist - a function that returns a linked list of paths
 * to the directories stored in the env
 * Return: a linked list, which contains the paths extracted
 * from the "PATH" environment variable.
*/
list_paths *paths_to_linkedlist()
{
list_paths *paths_linkedlists;
char *copied_variable, *path_variable, *token;

paths_linkedlists = NULL;

path_variable = _getenv("PATH");
if (path_variable == NULL)
return (NULL);

copied_variable = _strdup(path_variable);
if (copied_variable == NULL)
return (NULL);

token = strtok(copied_variable, ":");
while (token != NULL)/*looping tell the end*/
{
add_node(&paths_linkedlists, token);
token = strtok(NULL, ":");
}
free(copied_variable);
return (paths_linkedlists);
}

/**
 * add_node - a function that adds a new node at the beginning of a list_t list
 * @head: pointer to the head of list with the type list_paths
 * @path: pointer to path.
 * Return: the address of the new element, or NULL if it failed
*/
list_paths *add_node(list_paths **head, char *path)
{
list_paths *new;
int i = 0;
char *string_path;

while (path[i] != '\0')
i++;

new = malloc(sizeof(list_paths));
if (new == NULL)
return (NULL);

if (path)
{
string_path = _strdup(path);
if (string_path == NULL)
{
free(new);
return (NULL);
}
new->len = i;
new->path = string_path;
}
else
{
new->len = 0;
new->path = NULL;
}
new->next = (*head);

*head = new;
return (new);
}

/**
 * print_list - prints all the elements of a list_paths list
 * If str is NULL, print [0] (nil)
 * @h: pointer to the head of list with the type list_paths
 * Return: the number of nodes
*/
size_t print_list(const list_paths *h)
{
int count = 0;
size_t len = 0;
char n1 = '\n';

if (h == NULL)
return (0);

while (h)
{
if (h->path == NULL)
{
len = write(1, "[0] (nil)\n", 9);
write(1, &n1, 1);
fflush(stdout);
}
else
{
len += write(1, "[", 1);
len += write(1, &h->len, sizeof(h->len));
len += write(1, "] ", 2);
len += write(1, &h->path, sizeof(h->path));
len += write(1, "\n", 1);

fflush(stdout);
}
h = h->next;
count++;
}
return (count);
}
