#ifndef _shell_h_
#define _shell_h_

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
 * @buff_cpy: char type
 * @str: char type
 * @arr: char type
 */

typedef struct free_all_lists
{
	char *buff;
	char *str;
	char **arr;
	char **arv;
	char **envts;
} list;

/*functions for the shell*/
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);

/*to print to stout*/
int _printfchar(char c);
void _printfs(char *str, int line);
ssize_t _put(char *strs);
int _printnum(int num);

/*to strtok and return a char **array*/ 
char **token(char *buff, char *delim);
void forking(char **av, list all);

void envt(char **envt);

void free_all(list free_list, int ac);

#endif
