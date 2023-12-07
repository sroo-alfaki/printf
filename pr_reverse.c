#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * f_reverse - print string in reverse
 * @args: type args
 * Return: int
 */
int f_reverse(va_list args)
{
	char *s;
	int i, count = 0;

	s = va_arg(args, char *);

	if (s == NULL)
	{
		s = ("null");
	}
	for (i = 0; s[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = s[i];

		count += f_write(z);
	}
	return (count);
}
