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

/**
 * Constants for buffer sizes and command chaining
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

/**
 * Flags for convert_number()
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * Flag to control the use of system getline() and strtok
#define USE_GETLINE 0
#define USE_STRTOK 0

/**
 * History file settings
#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096

extern char **environ;

/**
 * Linked list structure for strings
 typedef struct liststr
 {
 int num;
 char *str;
 struct liststr *next;
 } list_t;

/**
 * Structure to pass arguments to functions
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
 char *cmd_buf;
 int cmd_buf_type;
 int readfd;
 int histcount;
 } info_t;

#define INFO_INIT
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL,
NULL, NULL, NULL, 0, 0, NULL, 0, 0, 0}

/**
 * Structure for built-in commands
 typedef struct builtin
 {
 char *type;
 int (*func)(info_t *);
 } builtin_table;

// Function prototypes
int interactive(info_t *info);
int is_delim(char c, char *delim);
int _isalpha(int c);
int _atoi(char *s);

#endif

