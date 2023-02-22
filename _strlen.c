#include "shell.h"
/**
 * _strlen - fun that is len of str
 *
 * @s: is a ASCII char , string to check
 *
 * Return: len of a str
 */
int _strlen(char *s)

{
	int i;

	if (s == NULL)
		return (0);

	for (i = 0; s[i] != '\0'; i++)
		;

	return (i);
}
