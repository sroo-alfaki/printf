#include "main.h"
#include <unistd.h>
/**
 * f_sstring - Prints a string
 * @args: list of variadic arguments
 * Return: The length of the string
 */

int f_sstring(va_list args)
{
	char *s = va_arg(args, char *);
	int count = 0;

	if (s == NULL)
		s = "null";

	while (*s != '\0')
	{
		if (*s < 32 || *s >= 127)
		{
			count += f_write('\\');
			count += f_write('x');
			count += f_write((*s >> 4) + ((*s >> 4) < 10 ? '0' : 'A' - 10));
			count += f_write((*s & 0xF) + ((*s & 0xF) < 10 ? '0' : 'A' - 10));
		}
		else
		{
			count += f_write(*s);
		}

		s++;
	}

	return (count);
}
