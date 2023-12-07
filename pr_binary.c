#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * f_binary - Print int converted to binary
 * @args: list of variadic arguments
 * Return: The number of printed binary
 */
int f_binary(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;

	if (n < 0)
	{
		count += f_write('-');
		n = -n;
	}

	if (n == 0)
	{
		count += f_write('0');
		return (count);
	}

	int bary[32];
	int i = 0;

	while (n > 0)
	{
		bary[i++] = n % 2;
		n /= 2;
	}

	for (int j = i - 1; j >= 0; j--)
	{
		count += f_write('0' + bary[j]);
	}

	return (count);
}
