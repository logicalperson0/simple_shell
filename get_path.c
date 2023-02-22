#include "shell.h"

/**
 * get_path - gets the path without inputting the full path
 * @buff: command parameter
 * @pathing: struct type called list
 *
 * Return: string with the full path
 */
char *get_path(list pathing, char *buff)
{
	char *str = "PATH";
	char *get, *dir;
	char **array;
	int e;

	e = envt_i(pathing, str);

	array = strtok_path(pathing, e, str);
	if (array == NULL)
		return (NULL);

	dir = find_dir(array, buff);
	if (dir == NULL)
	{
		free_all(array);
		return (NULL);
	}
	get = combine_path(dir, buff);
	if (get == NULL)
	{
		free_all(array);
		return (NULL);
	}
	free_all(array);

	return (get);
}
/**
 * strtok_path - sep str of path
 * @path: struct type list
 * @x: parameter index
 * @s: delimiter
 *
 * Return: array of str
 */
char **strtok_path(list path, int x, char *s)
{
	char *envt;
	int l;
	char **arr;
	char *d = ":\n";

	l = _strlen(s);

	envt = path.envts[x] + (l + 1);
	arr = token(envt, d);
	if (arr == NULL)
		return (NULL);
	return (arr);
}
