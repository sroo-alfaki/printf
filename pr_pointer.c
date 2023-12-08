#include "main.h"
#include <stdarg.h>
#include <stdint.h>

/**
 * f_pointer - Print int converted to pointer
 * @args: list of variadic arguments
 * Return: The number of printed address
 */

int f_pointer(va_list args)
{
	void *ptr = va_arg(args, void *);
	unsigned long long address = (unsigned long long)ptr;
	int j ,i = 0 ,count = 0;
	char hex[16];

	count += f_write('0');
	count += f_write('x');

	while (address > 0)
	{
		int remainder = address % 16;

		if (remainder < 10)
		{
			hex[i++] = '0' + remainder;
		}
		else
		{
			hex[i++] = 'a' + (remainder - 10);
		}
		address /= 16;
	}

	for (j = i - 1; j >= 0; j--)
	{
		count += f_write(hex[j]);
	}
	return (count);
}
