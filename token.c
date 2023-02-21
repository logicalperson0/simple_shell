#include "shell.h"

/**
 * token - to strtok and assign each arg to a array of char **
 *
 * @all: struct type list
 *
 * Return: double ptr to a array
 */
char **token(list all)
{
	int i = 0, ac = 0;

	all.buff_cpy = _strdup(all.buff);
	all.str = strtok(all.buff, " \n");

	while (all.str)
	{
		all.str = strtok(NULL, " \n");
		ac++;
	}

	all.arr = malloc(sizeof(char *) * (ac + 1));
	if (all.arr == NULL)
	{
		return (NULL);
	}
	all.str = strtok(all.buff_cpy, " \n");

	while (all.str)
	{
		all.arr[i] = all.str;
		all.str = strtok(NULL, " \n");
		i++;
	}
	all.arr[i] = NULL;
	/*free(all.buff_cpy);*/

	return (all.arr);
}
