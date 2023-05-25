#ifndef SHELL_H
#define SHELL_H

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

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define NORM 0
#define OR 1
#define AND 2
#define CHAIN 3

/* for convert_number() */
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

extern char **environ;

/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
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
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
} info_t;



/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

int hsh(info_t *, char **);

int che_bul(info_t *);

void find_comed(info_t *);
void cre_ch(info_t *);

int is_comid(info_t *, char *);
char *dup_ch(char *, int, int);
char *find_th(info_t *, char *, char *);

/* not use int loophsh(char **); */

void _puts_error(char *);
int putchar_error(char);
int _puy_fd(char c, int fd);
int _treefd(char *str, int fd);

int _strlen(char *);
int _strcmp(char *, char *);

char *sta_with(const char *, const char *);
char *_strcat(char *, char *);

char *_strcpy(char *, char *);
char *_strncpy(char *, char *, int);

char *_strncat(char *, char *, int);
char *_strchr_yu(char *, char);

char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

char **_strtok(char *, char *);

void list_free_str(char **);

int _buffer_free(void **);

int inter_mod(info_t *);
int is_delim(char, char *);

int _atoi_error(char *);

void error_print(info_t *, char *);
int prnt_deci(int, int);

char *_itoa(long int num, int base, int flags);

int exit_shell(info_t *);
int _change_dir(info_t *);

ssize_t in_bu(info_t *, char **, size_t *);
ssize_t get_in(info_t *);
void sigintHandler(int);

void cle_in(info_t *);
void set_t_info(info_t *, char **);
void info_free(info_t *, int);

char *_getenv(info_t *, const char *);
int _env(info_t *);
int _my_setenv(info_t *);


int _myunsetenv(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);
int env_list(info_t *);

char **get_environ(info_t *);

size_t print_list_str(const list_t *);
void list_free(list_t **);


size_t list_leng(const list_t *);
char **list_to_str(list_t *);
size_t print_list(const list_t *);

ssize_t gt_de_idx(list_t *, list_t *);
int delete_de_idx(list_t **, unsigned int);
list_t *add_de_end(list_t **, const char *, int);
list_t *de_starts(list_t *, char *, char);

int unset_al(info_t *, char *);


int set_al(info_t *, char *);
int print_al(list_t *);
int _myalias(info_t *);
int replace_al(info_t *);
char *_mem_cut(char *, char, unsigned int);

int is_nxt(info_t *, char *, size_t *);
void che_ne(info_t *, char *, size_t *, size_t, size_t);
int repla_vars(info_t *);
void comt_handl(char *);
int repla_str(char **, char *);

void *_realloc(void *, unsigned int, unsigned int);
int _getline(info_t *, char **, size_t *);
ssize_t read_buf(info_t *info, char *buf, size_t *i);

int populate_env(info_t *);

#endif
