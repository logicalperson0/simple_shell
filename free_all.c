#include "shell.h"

/**
 * free_all - frees all allocated mem in the heap
 * @free_list: of struct type list
 * @xc: parameter for arg on argc
 *
 * Return: 0 (chk)
 */
void free_all(list free_list, int xc)
{
	int i = 0;

	free(free_list.buff);
	while (xc > i)
	{
		free(free_list.arr[i]);
		i++;
	}
	free(free_list.arr);
	free(free_list.str);

}
