#include "shell.h"

/**
 * combine_path - Combines two strings of dir and
 * the cmd
 *
 * @dir: directory in the path.
 * @c: Represents a file in a directory of the path
 *
 * Return: string representing the full path
 */
char *combine_path(char *dir, char *c)
{
	int x, y, l;
	int dirlen, clen;
	char *com;

	if (dir == NULL || c == NULL)
		return (NULL);

	dirlen = _strlen(dir) + 1;
	clen = _strlen(c) + 1;
	l = dirlen + clen;

	com = (char *) malloc(sizeof(char) * l);
	if (com == NULL)
		return (NULL);

	for (x = 0; x < l; x++)
	{
		for (y = 0; dir[y] != '\0'; y++)
		{
			com[x] = dir[y];
			x++;
		}
		com[x] = '/';
		x++;
		for (y = 0; c[y] != '\0'; y++)
		{
			com[x] = c[y];
			x++;
		}
	}
	com[--x] = '\0';
	return (com);
}
