#ifndef _shell_h_
#define _shell_h_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

typedef struct free_all_lists
{
	char *buff;
	char *buff_cpy;
	char *str;
	char **arr;
} list;


char *_strdup(char *str);
int _strcmp(char *s1, char *s2);

void free_all(list free_list, int ac);

#endif
