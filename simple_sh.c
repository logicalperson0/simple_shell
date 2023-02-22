#include "shell.h"

/**
 * main - program that acts like the shell
 * @argc: count of av
 * @av: arg in terminal
 * @env: env of shell
 * Return: 0 for success
 */
int main(int argc, char **av, char **env)
{
	unsigned int piping = 0;
	size_t n = 0;
	list all = {NULL, NULL, NULL, NULL, NULL, 0};

	all.envts = env, all.arv = av;
	(void)argc;
	if (!isatty(STDIN_FILENO))
		piping = 1;
	if (piping == 0)
		_put("$ ");
	while (/*getline(&(all.buff), &n, stdin) != -1*/ 1)
	{
		all.count++;
		if (getline(&(all.buff), &n, stdin) == -1)
		{
			free(all.buff);
			exit(EXIT_FAILURE);
		}
		all.arr = token(all.buff, " \n");
			if (all.arr && all.arr[0])
			{
				if (_strcmp(all.arr[0], "exit") == 0 && (all.arr[1] == NULL))
				{
					free_all(all.arr);
					free(all.buff);
					exit(EXIT_SUCCESS);
				}
				if (_strcmp(all.arr[0], "env") == 0)
					envt(all.envts);
				else
					forking(all);
			}
		free_all(all.arr);
		free(all.buff);
		if (piping == 0)
			_put("$ ");
		all.buff = NULL;
	}
	free_envt(all.envts);
	exit(EXIT_SUCCESS);
}
