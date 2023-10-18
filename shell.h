#ifndef SHELL_H
#define SHELL_H

/*
 * Simple Shell Header File
 * Authors: Nwachiemu and Ngwuebo
 */

/* Libraries */
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

/* Constants */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2
#define USE_GETLINE 0
#define USE_STRTOK 0
#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096

/* Global variables */
extern char **environ;

/* Data Structures */
/**
 * struct liststr - representing a linked list of strings.
 * @num: An integer value associated with the string.
 * @str: A pointer to a character string.
 * @next: A pointer to the next element in the linked list.
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - containing information related to a command or process.
 * @arg: A pointer to the main command or argument.
 * @argv: An array of pointers to arguments.
 * @path: A pointer to the command's path.
 * @argc: The number of arguments in argv.
 * @line_count: The line count or position in input.
 * @err_num: Error number associated with the command.
 * @linecount_flag: Flag to indicate line counting.
 * @fname: A pointer to the filename.
 * @env: A linked list of environment variables.
 * @history: A linked list for command history.
 * @alias: A linked list of command aliases.
 * @environ: An array of environment variables.
 * @env_changed: Flag indicating environment changes.
 * @status: The status or exit code of the command.
 * @cmd_buf: An array of command buffers.
 * @cmd_buf_type: Type of command buffer.
 * @readfd: File descriptor for reading input.
 * @histcount: Count of history elements.
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
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT
{
	NULL, NULL, NULL, 0, 0, 0, 0, NULL,
	NULL, NULL, NULL, NULL, 0, 0, NULL,
0, 0, 0
}

/**
 * struct builtin - representing a built-in command in a shell.
 * @type: A pointer to a string identifying
 * the type or name of the built-in command.
 * @func: A function pointer to
 * the implementation of the built-in command.
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

/* Function Prototypes */
/* Prototypes for functions in toem_shloop.c */
int hsh(info_t, char *);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

/* Prototypes for functions in toem_parser.c */
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

/* And so on for all the other functions... */

#endif
