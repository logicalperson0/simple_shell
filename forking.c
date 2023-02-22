#include "shell.h"

/**
 * forking - fork to child if cmd found
 *
 * @all: struct type list
 * @av: argv parameter
 */
void forking(char **av, list all)
{
	pid_t my_pid;
	int statu, val;

	my_pid = fork();

	if (my_pid == -1)
	{
		perror("Error:");
		/*free_all(all, ac);*/
		exit (100);
	}

	if (my_pid == 0)
	{
		val = execve(all.arr[0], all.arr, NULL);
		if (val == -1)
		{
			perror(av[0]);
			/*free_all(all, ac);*/
			exit (EXIT_FAILURE);
		}
	}
	else
		wait(&statu);
}
