#include "main.h"
/**
 * f_octal - Print number octal
 * @args: list of variadic arguments
 * Return: The number of printed octal
 */

int f_octal(va_list args)
{
	int n = va_arg(args, int);
	int count = 0, oct[32], i = 0, j;

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
		oct[i] = n % 8;
		n /= 8;
		i++;
	}

	for (j = i - 1; j >= 0; j--)
	{
		count += f_write('0' + oct[j]);
	}

	return (count);
}
