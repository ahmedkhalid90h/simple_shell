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

/* for read/write buffers ? */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining ? */
#define NORM	0
#define OR		1
#define AND		2
#define CHAIN	3

/* for convert_number() ? */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

extern char **environ;

/**
 * struct liststr - singly linked list is linked list
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
 *		allowing uniform prototype for function pointer struct pointer struct
 *@arg_c: a string generated from getline containing arguements pointer
 *@argv_x: an array of strings generated from arg is arg
 *@path_f: a string path for the current command  line
 *@argc: the argument count  for the current command line
 *@line_count_: the error count  for the current command line
 *@err_num: the error code for exit()s  exit fun
 *@linecount_flag: if on count this line of input pointer
 *@filename: the program file name
 *@env: linked list local copy of environ is env
 *@environ: custom modified copy of environ from LL env 
 *@alias: the alias node list
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command line
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@_f: the fd from which to read line input
 */
typedef struct passinfo
{
	char *arg_c;
	char **argv_x;
	char *path_f;
	int argc;
	unsigned int line_count_;
	int err_num;
	int linecount_flag;
	char *filename;
	list_t *env;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd_f;
} info_t;


#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0}

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



char *starts_with_needl(const char *, const char *);
void sigint_Handler(int);
void initializes_info(info_t *);
int interactive_mode(info_t *);
int _err_putchar(char);
ssize_t get_input_nline(info_t *);
ssize_t input_buf(info_t *, char **, size_t *);
void check_next_f(info_t *, char *, size_t *, size_t , size_t );
int is_next_c(info_t *, char *, size_t *);
void set_info_initializes(info_t *, char **);
int is_delimeter_char(char, char *);
void find_commd(info_t *);
char *find_path_f(info_t *, char *, char *);
int is_cmd_(info_t *, char *);
char *dupl_chars(char *, int, int);
void create_child_fork(info_t *);
void free_str_list(char **);
void free_list_node(list_t **);
int _free_buf(void **);
void print_err(info_t *, char *);
void _err_puts(char *);
int print_decimal_num(int, int);
char **list_to_str(list_t *);
int hsh(info_t *, char **);
char **get_environment(info_t *);
int is_delimeter_char(char, char *);
int _puts_fd(char *, int);
void _puts_str(char *);
int populate_env_list(info_t *);






size_t list_length(const list_t *);


int _putchar(char);
int _strlen(char *);
char **_strtok(char *, char *);
char *_strdup(const char *);
char *_strcat(char *, char *);
char *_getenv(info_t *, const char *);
char *_strcpy(char *, char *);
int _strcmp(char *, char *);


#endif