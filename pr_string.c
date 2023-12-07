#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * f_string - Prints a string
 * @args: list of variadic arguments
 * Return: The length of the string
 */
int f_string(va_list args)
{
	char *s = va_arg(args, char *);
	int count = 0;

	if (s == NULL)
		s = ("null");

	while (*s != '\0')
	{
		count += f_write(*s);
		s++;
	}

	return (count);
}
