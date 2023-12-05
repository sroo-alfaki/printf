#include "main.h"

/**
 *print_string - returns print string
 *@ *str: input char
 *@*printed_chars: print char or string
 *Return: always 0
 */


void print_string(const char *str, int *printed_chars)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	write(1, str, len);
	*printed_chars += len;
}
