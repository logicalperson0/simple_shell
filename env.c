#include "shell.h"

/**
 * envt - envt of terminal
 * @envt: parameter
 */

void envt(char **envt)
{
	unsigned int i;

	i = 0;

	while (envt[i] != NULL)
	{
		_put(envt[i]);
		_put("\n");
		i++;
	}
}
