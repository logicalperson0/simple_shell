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
