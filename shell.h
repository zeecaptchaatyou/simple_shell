#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/types.h>
#include <string.h>

int _putchar(char c);
char *_strchr(const char *str, int ch);
int _strcmp(const char *str1, const char *str2);
int _strlen(char *s);
char *_getenv(const char *name);
int _strncmp(const char *str1, const char *str2, size_t n);
size_t strspn(const char *s, const char *accept);
char *_strtok(char *str_ptr, const char *delimiters);

#endif
