#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

/**
 * main - program that acts like the shell
 *
 * Return: 0 for success
 */

int main(int argc, char **av, char **env)
{
	int chk;
	size_t n = 0;
	list all = {NULL, NULL, NULL, NULL};
	/*char *buff = NULL, *buff_cpy = NULL, *str = NULL;*/
	/*pid_t my_pid;*/
	struct stat status;
	/*char **arr;*/

	(void)argc;

	while (1)
	{
		_printfs("#cisfun$ ");
		if (getline(&(all.buff), &n, stdin) == -1)
		{
			_printfchar('\n');
			/*free_all(all, ac);*/
			return (-1);
		}

		all.arr = token(all);
		
		if (all.arr[0] == NULL)
			continue;

		if (_strcmp(all.arr[0], "exit") == 0 && (all.arr[1] == NULL))
		{
			free(all.arr);
			exit(0);
		}
		if (_strcmp(all.arr[0], "env") == 0)
		{
			envt(env);
			continue;
		}

		chk = stat(all.arr[0], &status);
		if (chk == -1)
		{
			perror(av[0]);
			continue;
		}

		forking(av, all);

		free(all.buff);
		all.buff = NULL;
	}
	/*free_all(all, ac);*/

	/*free(buff);
	free(buff_cpy);
	free(arr);*/

	return (0);
}
