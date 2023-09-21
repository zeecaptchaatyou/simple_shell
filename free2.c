#include "shell.h"


/**
* free_list - Frees a singly linked list
* @head: Pointer to the head of the list
*/
void free_list(list_paths *head)
{
list_paths *ptr = head;
list_paths *nextNode;

while (ptr != NULL)
{
nextNode = ptr->next;
free(ptr->path);
free(ptr);
ptr = nextNode;
}}
