#include "shell.h"
#include <unistd.h>

/**
 * _printfs - func that prints to stout
 *
 * @str: parameter
 * @line: parameter
 * Return: stout of args, if null write (null)
 */

void _printfs(char *str, int line)
{
	int i = 0;
	char *s;

	s = str;
	if (s == NULL)
	{
		write(1, "(null)", 6);
	}
	else
	{
		while (s[i] != '\0')
		{
			_printfchar(s[i]);
			i++;
		}
	}
	if (line == 0)
		write(1, "\n", 1);
}
