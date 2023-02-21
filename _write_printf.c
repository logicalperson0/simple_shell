#include "shell.h"
#include <unistd.h>

/**
 * _printfs - func that prints to stout
 *
 * @str: parameter
 * Return: stout of args, if null write (null)
 */

int _printfs(char *str)
{
	int i = 0;
	char *s;

	s = str;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		while (s[i] != '\0')
		{
			_printfchar(s[i]);
			i++;
		}
	}
	return (i);
}
