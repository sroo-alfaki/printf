#include "main.h"
/**
 * f_unsigned - Print int unsigned
 * @args: list of variadic arguments
 * Return: The number of unsigned
 */
int f_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;
	unsigned int revNum = 0;

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
