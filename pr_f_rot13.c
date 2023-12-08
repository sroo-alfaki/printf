#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 *f_rot13 - Print to rot13'ed string
 *@args: list of variadic arguments
 *Return: The number of printed binary
 */

int f_rot13(va_list args)
{
	char *s = va_arg(args, char *);
	int count = 0;
	char c;

	if (s == NULL)
	{
		s = "null";
	}

	while ((c = *s++) != '\0')
	{
		if (c >= 'a' && c <= 'z')
		{
			c = ((c - 'a') + 13) % 26 + 'a';
		}
		else if (c >= 'A' && c <= 'Z')
		{
			c = ((c - 'A') + 13) % 26 + 'A';
		}
		count += f_write(c);
	}

	return (count);
}
