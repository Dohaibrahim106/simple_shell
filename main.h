#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdbool.h>

#define _DELIMITER " \t\r\n\a\""

/*env command*/
void zd_env(void);
char *zd_getenv(char *nameptr);
extern char **environ;
int zd_env_builtin(const char *nameptr, const char *val);

/*exit command*/
int zd_exit(char *lineptr, int *stat, int counter,
char *programe_name, char *lin);

/*Excution commands*/
char *zdhandle_new_line(char *line);
int zd_builtin_command(char *programe_name, char *lineptr,
int *stat, int counter, char *lin);
char *get_total_path(char *lineptr);
char **zd_argv(char *lineptr);
int zd_excut(char *user_cmd, char **argv, char *env[], int *stat);
void zdexcute_notFound(char *lineptr,
char **command_argv,
char *envi[], int *stat);

/*Handeled functions*/
char *zd_strdup(char *string);
void zd_strcat(char *string1, const char *string2);
int zd_strlen(char *p);
char *zd_strcpy(char *dest, char *src);
int zd_strcmp(char *string1, char *string2);
int zd_atoi(char *string);
char *zdprint_num(int num);

/*non,interactive modes*/
void zd_non_interactive_mode(char **argv);
void zd_interactive_mode(char **argv);

/*Errors*/
void zd_print_errors(char *prog_name, int counter, int stat, char *lineptr);
void zd_exit_error(char *prog_name, char *counter, char *lineptr);
void zd_command_error(char *prog_name, char *counter, char *lineptr);
void zd_path_errors(char *prog_name, char *counter, char *lineptr);

/*Advanced functions*/
ssize_t zd_getline(char **lineptr, size_t *n, FILE *stream);
char *zd_strtok(char *string, const char *delimiters);


#endif
