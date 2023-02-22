#include "shell.h"

/**
 * _printnum - prints out a num
 *
 * @num: parameter
 *
 * Return: nums printed
 */
int _printnum(int num)
{
	int i = 1, j = 0;
	unsigned int k;

	k = num;

	while (k / i > 9)
		i *= 10;

	while (i != 0)
	{
		j += _printfchar(k / i + '0');

		k %= i;
		i /= 10;
	}
	return (j);
}
