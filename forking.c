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
	char *cmd, *tempo;

	my_pid = fork();
	if (my_pid != 0)
		wait(0);
	else
	{

		tempo = all.arr[0];
		cmd = get_path(all, all.arr[0]);
		if (cmd == NULL)
		{
			chk = stat(tempo, &status);
			if (chk == -1)
			{
				error_p(all.arv[0], all.count, all.buff);
				_printfs(": not found", 0);
				exit(100);
			}
			cmd = tempo;
		}
		all.arr[0] = cmd;

		if (all.arr[0] != NULL)
		{
			val = execve(all.arr[0], all.arr, all.envts);
			if (val == -1)
			{
				error_p(all.arv[0], all.count, all.buff);
				exit(1);
			}
		}
	}
}
