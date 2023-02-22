#ifndef _shell_h_
#define _shell_h_
#define i(x) (void)(x)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>


/**
 * struct free_all_lists - struct type to hold most variables of main
 * @buff: char type
 * @str: char type
 * @arr: char type
 * @arv: char type
 * @envts: char type
 * @count: int type
 */

typedef struct free_all_lists
{
	char *buff;
	char *str;
	char **arr;
	char **arv;
	char **envts;
	int count;
} list;

/*functions for the shell*/
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);

/*to print to stout*/
int _printfchar(char c);
void _printfs(char *str, int line);
ssize_t _put(char *strs);
int _printnum(int num);

/*to strtok and return a char **array by child process*/
char **token(char *buff, char *delim);
void forking(list all);

/*prints out the buildin envt*/
void envt(char **envt);

/*path to fine the cmds; without inputting the full path*/
int envt_i(list e, char *s);
char *find_dir(char **dir_path, char *c);
char *combine_path(char *dir, char *c);
char *get_path(list pathing, char *buff);
char **strtok_path(list path, int x, char *s);

/*frees the heap*/
void free_all(char **array);

/* prints out the error*/
void error_p(char *argv, int c, char *cmd);
void error_out(char *argv, int c, char *cmd);

/* for the ^C interput assigned int*/
unsigned int sig_flag;

#endif
