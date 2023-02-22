#include "shell.h"

/**
 * token - to strtok and assign each arg to a array of char **
 *
 * @all: struct type list
 *
 * Return: double ptr to a array
 */
char **token(char *buff, char *delim)
{
	int i = 0, ac = 0;
	char *buff_cpy = NULL;
	char *str = NULL;
	char **buffi = NULL;

	buff_cpy = _strdup(buff);
	str = strtok(buff, delim);

	while (str)
	{
		str = strtok(NULL, delim);
		ac++;
	}

	buffi = malloc(sizeof(char *) * (ac + 1));
	if (buffi == NULL)
	{
		return (NULL);
	}
	str = strtok(buff_cpy, delim);

	while (str)
	{
		buffi[i] = _strdup(str);
		str = strtok(NULL, delim);
		i++;
	}
	buffi[i] = NULL;
	free(buff_cpy);

	return (buffi);
}
