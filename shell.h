#ifndef MAIN_H
#define MAIN_H

#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define NOT_FOUND 127
#define PERMISSION_DENIED 126
#define EXIT_ERROR 2
#define INTERACTIVE_MODE 1
#define NON_INTERACTIVE_PIPE 2
#define NON_INTERACTIVE_MODE 0
#define ERROR -1
#define TOK_D " \t\r\n\a\""


/**
 * struct list_paths - structure of a linked list of env paths
 * @path:env path
 * @len: path length
 * @next: pointer to the next node
*/
typedef struct list_paths
{
	char *path;
	size_t len;
	struct list_paths *next;
} list_paths;

extern char **environ;

list_paths *paths_to_linkedlist();
size_t print_list(const list_paths *h);
void free_list(list_paths *head);
list_paths *add_node(list_paths **head, char *path);
unsigned int char_count(char *string, char character);



int _atoi(char *str);



int mode_checker(int argc);
char *access_checker(char *line, list_paths *path_list);
char *scan_userInput(list_paths *current);
void free_array(char **argv);
void free_all(char *command, char **command_array);
void command_executer(char *path, char **av, char **env, int *status);
void scan_cmd_file(char *file);
char *input_file_checker(char *file);
void free_list(list_paths *head);

char *num_to_char(int num);

/* error handling prototypes*/
void print_error(char *shell_name, int count, char *cmd_arr, int error_type);

char *get_status(int n);
char *get_process_id();
char *_getenv(const char *name);
int builtin_handler(char *command, char **command_array, list_paths *current,
char *shell_name, int count, int *status,
list_paths *env_list, char **command_lines, char **argv);
void non_builtin_cmd_handler(char **command_array, char *env[], int *status,
int count, list_paths *current, char *argv[]);
int custom_cd(char **command_array, char **argument_vector);
void _setenv(char *key, char *value, list_paths *current);
char **scan_command_files(int op_mode, char *file_name, char *shell_name);
char **noninteractive_files_handler(char *file_name, char *shell_name);

/*file dir_check*/
int dir_check(char *cmd, char **arg_v, int count, char **cmd_arr, int *status,
char *prev_cmdl);

void cant_open_handler(char *program_name, int counter, char *file_name);

/*parsers.c prototypes*/
unsigned int charCounter(char *str, char c);
char **line_parser(char *line, int status);
void print_env(int *status);
int line_count(char *line);
char *token_proccessor(char *token, int status);

char **noninteractive_pipes_handler();
char *get_non_interactive_command(char **command_lines, int count);
void permission_handler(char **command_array, int count,
char *executable, int *status, char *command);
void process_command(char *command, int *status, char ***command_array);

char **allocate_vector(int size);
void free_vector(char **vector);

int tokenize_command(char *command, int status, char **argument_vector);
char *flags_handler(char *token, char *cmd,
char **arg_v, int status);
void free_whole(char **command_lines, int count, list_paths *env,
list_paths *current, char *command, char **command_array);
void exit_handler(char *command, char **command_array, list_paths *current,
char *shell_name, int count, int *status, list_paths *env,
char **command_lines);

void comments_handler(char *input);

/* string modifying functions*/
char *_strtok(char *str, const char *delim);
int _strlen(char *s);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);

/* sidechicks functions*/
char **txtTOarr(char *text);
char *numTOchar(int num);
void itos(int n, char *str);

#endif
