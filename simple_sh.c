#include "shell.h"
/**
 * signals - handles the ^C signal interupt
 * @i: parameter
 */
static void signals(int i)
{
	(void)i;
	if (sig_indicator == 0)
		_put("\n$ ");
	else
		_put("\n");
}

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
	signal(SIGINT, signals);
	if (!isatty(STDIN_FILENO))
		piping = 1;
	if (piping == 0)
		_put("$ ");
	sig_indicator = 0;
	while (getline(&(all.buff), &n, stdin) != -1)
	{
		all.count++;
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
	if (-1 && piping == 0)
		_printfchar('\n');
	free(all.buff);
	exit(EXIT_SUCCESS);
}
