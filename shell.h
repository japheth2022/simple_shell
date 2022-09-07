#ifndef SHELL_H

#define SHELL_H



#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <signal.h>

#include <unistd.h>

#include <sys/wait.h>

#include <sys/stat.h>



/* size of buffer for user input */

#define READ_BUF 1000



#define DELIM " \a\t\r\n"



/* command type */

#define INTERNAL_CMD 1

#define EXTERNAL_CMD 2

#define PATH_CMD 3

#define INVALID_CMD -1



/* global environ variable declaration */

extern char **environ;



typedef struct internal_func

{

	char *cmd_name;
	void (*func)(char **command);

} map_func;



/* commands */

void env(char **);

void ch_dir(char **);

void quit(char **);



/* utilisable function */

void ctrl_C(int);

char *_getline(void);

char **tokenize(char *, const char *);

void shell_execute(char **, int);

int check_command(char *);

void execute(char **, int);

/* helper function */

int print(char *, int);

void (*get_func(char *))(char **);

/*string functions */

int _strlen(char *);

int _strcmp(char*, char *);


void *_realloc(void *, int, int);

char *_getenv(char *);

#endif 
