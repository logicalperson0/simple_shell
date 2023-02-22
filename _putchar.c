#include <unistd.h>
#include <stdarg.h>
#include "shell.h"

/**
 * _printfchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _printfchar(char c)

{
	return (write(1, &c, 1));
}

/**
 * _put - write to stdout
 * @strs: parameter
 *
 * Return: num of char printed
 */
ssize_t _put(char *strs)
{
	ssize_t i = 0, j;

	while (strs[i])
		i++;
	j = write(1, strs, i);
	if (j != i)
	{
		perror("Fatal Error");
		return (-1);
	}
	return (j);
}
