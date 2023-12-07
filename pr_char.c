#include "main.h"
#include <stdio.h>
/**
 * f_char - Print a char
 * @args: list of variadic arguments
 * Return: The length of the character
 */

int f_char(va_list args)
{
	char c = va_arg(args, int);

	return (f_write(c));
}
