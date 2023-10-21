#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CMD_NORM
#define CMD_OR
#define CMD_AND
#define CMD_CHAIN

#define CONVERT_LOWERCASE
#define CONVERT_UNSIGNED

#define USE_GETLINE
#define USE_STRTOK

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly
 * @num: the num
 * @str: str
 * @next: points in
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo
 *@arg: a string
 *@argv: an array
 *@path: a string p
 *@argc: the arg count
 *@line_count: the ero
 *@err_num: the erro
 *@linecount_flag: if on
 *@fname: pro name
 *@env: linked li
 *@environ: custom
 *@history: the history
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return
 *@cmd_buf: address
 *@cmd_buf_type: CMD_type
 *@readfd: the fd
 *@histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} true_t;

#define CHECK_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains a builtin str
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(true_t *);
} builtin_table;


int hsh(true_t *, char **);
int find_builtin(true_t *);
void find_cmd(true_t *);
void fork_cmd(true_t *);

int is_cmd(true_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(true_t *, char *, char *);

int loophsh(char **);

void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int hd);
int _putsfd(char *str, int hd);

int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

char **strtow(char *, char *);
char **strtow2(char *, char);

char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

int bfree(void **);


int interactive(true_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

int _erratoi(char *);
void print_error(true_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);


int _myexit(true_t *);
int _mycd(true_t *);
int _myhelp(true_t *);

int _myhistory(true_t *);
int _myalias(true_t *);

ssize_t get_input(true_t *);
int _getline(true_t *, char **, size_t *);
void sigintHandler(int);

void clear_info(true_t *);
void set_info(true_t *, char **);
void free_info(true_t *, int);

char *_getenv(true_t *, const char *);
int _myenv(true_t *);
int _mysetenv(true_t *);
int _myunsetenv(true_t *);
int populate_env_list(true_t *);

char **get_environ(true_t *);
int _unsetenv(true_t *, char *);
int _setenv(true_t *, char *, char *);

char *get_history_file(true_t *check);
int write_history(true_t *check);
int read_history(true_t *check);
int build_history_list(true_t *check, char *buf, int linecount);
int renumber_history(true_t *check);

list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

int is_chain(true_t *, char *, size_t *);
void check_chain(true_t *, char *, size_t *, size_t, size_t);
int replace_alias(true_t *);
int replace_vars(true_t *);
int replace_string(char **, char *);

#endif
