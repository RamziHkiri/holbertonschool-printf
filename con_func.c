#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"
/**
 * print_c - print character
 * @params:variadic arguments
 * Return:none
 */
int print_c(va_list params)
{
	char c;

	c = va_arg(params, int);
	putchar(c);
	return (1);
}
/**
 * print_s - print string
 * @params:variadic arguments
 * Return:none
 */
int print_s(va_list params)
{
	int i;
	char *s;

	s = va_arg(params, char *);
	if (s)
	{
		for (i = 0 ; s[i] != '\0' ; i++)
		{
			putchar(s[i]);
		}

	}
	else
	{
		putchar('(');
		putchar('n');
		putchar('u');
		putchar('l');
		putchar('l');
		putchar(')');
		i = 6;
	}
	return (i);
}
