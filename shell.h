#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>
#include <limits.h>

extern char **environ;

/* str.c */
int _putchar(char c);
void _puts(char *str);
int _strlen(char *str);
int _atoi(char *str);
char *_strdup(char *str);

/* str2.c */
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);

char **tokenizee(char *command, char *delim);
void prompt(void);
void _printerror(char *error);

/* memory */
void free_s(char **pp);
int free_p(void **ptr);

char *_getpath(char *command);
int _getenv(char *command, char **args);
void exiting(char *command, int status, char **args);
int _child(char *token, char **args);

#endif
