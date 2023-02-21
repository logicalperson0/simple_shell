#include "shell.h"

void envt(char **envt)
{
	unsigned int i;

	i = 0;

	while (envt[i] != NULL)
	{
		printf("%s\n", envt[i]);
		i++;
	}
}
