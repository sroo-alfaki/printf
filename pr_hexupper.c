#include "main.h"
/**
 * f_hex_upper - Print hex upper
 * @args: list of variadic arguments
 * Return: The number of f_hex_upper
 */

int f_hex_upper(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;
	char hex[32];
	int i = 0, j, rem;

	if (n == 0)
	{
		count += f_write('0');
		return (count);
	}
	while (n > 0)
	{
		rem = n % 16;
		if (rem < 10)
		{
			hex[i] = '0' + rem;
		}
		else
		{
			hex[i] = 'A' + rem - 10;
		}
		n /= 16;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		count += f_write(hex[j]);
	}
	return (count);
}
