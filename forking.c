#include "shell.h"

/**
 * forking - fork to child if cmd found
 *
 * @all: struct type list
 */
void forking(list all)
{
	pid_t my_pid;
	int val, chk;
	struct stat status;

	chk = stat(all.arr[0], &status);
	if (chk == -1)
	{
		error_p(all.arv[0], all.count, all.buff);
		_printfs(": not found", 0);
	}

	my_pid = fork();

	if (my_pid == -1)
	{
		error_p(all.arv[0], all.count, all.buff);
		_printfs(": not found", 0);
		/*exit(EXIT_FAILURE);*/
	}

	else if (my_pid == 0)
	{
		val = execve(all.arr[0], all.arr, all.envts);
		if (val == -1)
		{
			/*error_p(all.arv[0], all.count, all.buff);*/
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(0);
}
