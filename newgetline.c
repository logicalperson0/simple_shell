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

int main(int anc, char **av)
{
	int val, ac = 0, stat, i = 0, j = 0;
	size_t n = 0;
	char *buff = NULL, *buff_cpy = NULL;
	char *str = NULL;
	pid_t my_pid;
	char **arr;

	(void)anc;

	while (1)
	{
		printf("#cisfun$ ");
		if (getline(&buff, &n, stdin) == -1)
		{
			/*putchar('\n');*/
			return (-1);
		}

		buff_cpy = strdup(buff);
		str = strtok(buff, " \n");

		while (str)
		{
			str = strtok(NULL, " \n");
			ac++;
		}

		arr = malloc(sizeof(char *) * (ac + 1));
		str = strtok(buff_cpy, " \n");

		while (str)
		{
			arr[i] = str;
			str = strtok(NULL, " \n");
			i++;
		}
		arr[i] = NULL;

		i = 0;
		/*printf("%d\n", i - 1);*/
		
		if (arr[0] == NULL)
			continue;

		if (strcmp(arr[0], "exit") == 0 && (arr[1] == NULL))
			exit(0);

		my_pid = fork();

		if (my_pid == -1)
		{
			perror("Error");
			return (-1);
		}

		if (my_pid == 0)
		{
			val = execve(arr[0], arr, NULL);
			if (val == -1)
			{
				perror(av[0]);
				return (-1);
			}
		}
		else
			wait(&stat);
	}

	free(buff);
	free(buff_cpy);
	while (j < ac)
	{
		free(arr[j]);
		j++;
	}
	free(arr);

	return (0);
}
