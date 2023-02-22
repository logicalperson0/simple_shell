#include "shell.h"

/**
 * free_all - frees the heap
 *
 * @array: parameter
 */
void free_all(char **array)
{
	int i;

	for (i = 0; array[i]; i++)
		free(array[i]);
	free(array);
}

/**
 * free_envt - frees the envt
 *
 * @envts: parameter
 */
void free_envt(char **envts)
{
	unsigned int i;

	for (i = 0; envts[i]; i++)
		free(envts[i]);
	free(envts);
}
