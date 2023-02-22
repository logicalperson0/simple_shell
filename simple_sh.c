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
	unsigned int piping = 0;
	size_t n = 0;
	list all = {NULL, NULL, NULL, NULL, NULL};
	struct stat status;
	all.envts = env;
	all.arv = av;

	(void)argc;

	if (!isatty(STDIN_FILENO))
		piping = 1;
	if (piping == 0)
		_put("$ ");

	while (getline(&(all.buff), &n, stdin) != -1)
	{
		/*_put("$ ");*/
		/*if (getline(&(all.buff), &n, stdin) == -1)
		{
			_printfchar('\n');
			free(all.arr);
			return (-1);
		}*/

		all.arr = token(all.buff, "\n");
		
		if (all.arr[0] == NULL)
		{
			continue;
		}

		if (_strcmp(all.arr[0], "exit") == 0 && (all.arr[1] == NULL))
		{
			free(all.arr);
			exit(EXIT_SUCCESS);
		}
		if (_strcmp(all.arr[0], "env") == 0)
		{
			envt(all.envts);
			continue;
		}

		chk = stat(all.arr[0], &status);
		if (chk == -1)
		{
			perror(all.arv[0]);
			continue;
		}

		forking(av, all);

		free(all.buff);
		if (piping = 0)
			_put("$ ");

		all.buff = NULL;
	}
	/*free_all(all, ac);*/

	/*free(buff);
	free(buff_cpy);
	free(arr);*/

	exit(EXIT_SUCCESS);
}
