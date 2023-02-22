#include "shell.h"

/**
 * error_p - prints message error when cmd not found
 * @c: track of num of cmds run
 * @argv: name of exe file of the shell
 * @cmd: cmd not found
 */
void error_p(char *argv, int c, char *cmd)
{
	_printfs(argv, 1);
	_printfs(": ", 1);
	_printnum(c);
	_printfs(": ", 1);
	_printfs(cmd, 1);
}
