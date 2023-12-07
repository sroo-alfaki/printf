#include "main.h"
#include <stdarg.h>

/**
 * f_integer - Prints a integer
 * @args: list of variadic arguments
 * Return: The length of the string
 */
int f_integer(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	int revNum = 0;

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
		revNum = revNum * 10 + n % 10;
		n /= 10;
	}

	while (revNum > 0)
	{
		count += f_write('0' + revNum % 10);
		revNum /= 10;
	}

	return (count);
}
