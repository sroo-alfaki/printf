#include "main.h"
#include <unistd.h>
#include <stdio.h>

/**
 * f_write - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1
 */
int f_write(char c)
{
	return (write(1, &c, 1));
}
