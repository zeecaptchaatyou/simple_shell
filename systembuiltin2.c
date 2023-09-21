#include "shell.h"

/**
 * noninteractive_pipes_handler - processes shell commands with pipes
 * Return: an array of chars
 */
char **noninteractive_pipes_handler()
{
char c[2048], *text_read, **cmd_lines;
size_t total_characters_read = 0;
ssize_t bytes_read;
int i = 0, flags = 0;

cmd_lines = NULL;
text_read = NULL;
while ((bytes_read = read(STDIN_FILENO, c, 2048)) > 0)
{
total_characters_read = total_characters_read + bytes_read;
}
if (bytes_read == -1)
{
perror("reading error");
exit(ERROR);
}
if (total_characters_read > 2048)
c[2048 - 1] = '\0';
else
c[total_characters_read - 1] = '\0';

for ( ; c[i]; i++)
{
if (c[i] != ' ')
flags = 1;
}
if (flags == 0)
return (NULL);
total_characters_read = _strlen(c);
text_read = (char *)malloc(sizeof(char) * (total_characters_read + 1));
if (text_read != NULL)
{
_strcpy(text_read, c);
text_read[total_characters_read] = '\0';
cmd_lines = txtTOarr(text_read);
}
return (cmd_lines);
}

/**
 * noninteractive_files_handler - processes shell commands in a file
 * @file_name: name of file with shell commands
 * @shell_name: name of shell to use
 * Return: pointer to char array with output
 * Opens file, reads each line.
 * pointer to char array with output.
 */
char **noninteractive_files_handler(char *file_name, char *shell_name)
{
struct stat stat_file;
char *text, **cmd_lines;
size_t letters_read;
int fd;

if (stat(file_name, &stat_file) != -1)
{
if (S_ISREG(stat_file.st_mode))
{
fd = open(file_name, O_RDONLY);
if (fd  == -1)
exit(ERROR);
if (stat_file.st_size == 0)
exit(0);
text = malloc((stat_file.st_size + 1) * sizeof(char));
if (!text)
return (NULL);
letters_read = read(fd, text, stat_file.st_size);
if ((int) letters_read == -1)
{
perror("Error reading");
}
close(fd);
text[letters_read - 1] = '\0';
if (text)
cmd_lines = txtTOarr(text);
return (cmd_lines);
}
else
exit(0);
}
else
{
cant_open_handler(shell_name, 0, file_name);
exit(127);
}
return (NULL);
}

