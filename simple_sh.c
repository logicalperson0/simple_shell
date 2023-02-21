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
	int val, ac = 0, statu, i = 0, chk;
	size_t n = 0;
	list all = {NULL, NULL, NULL, NULL};
	/*char *buff = NULL, *buff_cpy = NULL, *str = NULL;*/
	pid_t my_pid;
	struct stat status;
	/*char **arr;*/

	(void)argc;

	while (1)
	{
		_printfs("#cisfun$ ");
		if (getline(&(all.buff), &n, stdin) == -1)
		{
			/*putchar('\n');*/
			/*free_all(all, ac);*/
			return (-1);
		}

		all.buff_cpy = _strdup(all.buff);
		all.str = strtok(all.buff, " \n");

		while (all.str)
		{
			all.str = strtok(NULL, " \n");
			ac++;
		}

		all.arr = malloc(sizeof(char *) * (ac + 1));
		if (all.arr == NULL)
		{
			free(all.arr);
			return (-1);
		}
		all.str = strtok(all.buff_cpy, " \n");

		while (all.str)
		{
			all.arr[i] = all.str;
			all.str = strtok(NULL, " \n");
			i++;
		}
		all.arr[i] = NULL;
		/*free(all.buff_cpy);*/
		i = 0;
		
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
				return (-1);
			}
		}
		else
			wait(&statu);

		free(all.buff);
		all.buff = NULL;
	}
	free(all.buff);

	/*free(buff);
	free(buff_cpy);
	free(arr);*/

	return (0);
}
