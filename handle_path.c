#include "shell.h"

/**
 * envt_i - to get the index of the envt
 *
 * @e: parameter for the struct list type
 * @s: parameter
 *
 * Return: the index
 */
int envt_i(list e, char *s)
{
	int x, y = 0, c;

	c = _strlen(s);

	for (x = 0; e.envts[x] != NULL; x++)
	{
		while (y < c)
		{
			if (e.envts[x][y] != s[y])
				break;
			y++;
		}
		if (y == c && e.envts[x][y] == 61)
			return (x);
	}
	return (-1);
}

/**
 * find_dir - to get thw dir of the envt index
 *
 * @dir_path: parameter
 * @c: char str type
 * Return: ptr to the dir path
 */
char *find_dir(char **dir_path, char *c)
{
	int i, j;
	char *x, *y = NULL;
	size_t s = 0;
	struct stat status;

	x = getcwd(y, s);
	if (x == NULL)
		return (NULL);
	if (c[0] == '/')
		c += 1;
	for (i = 0; dir_path[i] != NULL; i++)
	{
		j = chdir(dir_path[i]);
		if (j == -1)
		{
			perror("Error");
			return (NULL);
		}
		j = stat(c, &status);
		if (j == 0)
		{
			chdir(x);
			free(x);
			return (dir_path[i]);
		}
	}
	chdir(x);
	free(x);
	return (NULL);
}
