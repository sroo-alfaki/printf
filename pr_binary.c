#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>
#include <limits.h>
/**
 * f_binary - Print int converted to binary
 * @args: list of variadic arguments
 * Return: The number of printed binary
 */
int f_binary(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	int bary[32];
	int j, i = 0;

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

	while (n > 0)
	{
		bary[i++] = n % 2;
		n /= 2;
	}

	for (j = i - 1; j >= 0; j--)
	{
		count += f_write('0' + bary[j]);
	}

	return (count);
}
