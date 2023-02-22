#include "shell.h"
#include <stdlib.h>

/**
 * _strdup - function that returns a pointer to a newly
 * allocated space in memory which contains a
 * copy of the string given as a parameter.
 * @str: Parameter for a str
 * Return: ptr to a str
 */
char *_strdup(char *str)
{
	char *ptr;
	unsigned int i, j = 0;

	if (str == NULL)
		return (NULL);

	while (str[j] != '\0')
		j++;

	ptr = (char *)malloc((j + 1) * sizeof(char));

	if (ptr == NULL)
		return (NULL);

	for (i = 0; i <= (j); i++)
	{
		ptr[i] = str[i];
	}
	return (ptr);
}
