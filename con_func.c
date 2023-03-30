#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"
/**
 * print_c - print character
 * @params:variadic arguments
 * Return:none
 */
void print_c(va_list params)
{
	char c;

	c = va_arg(params, int);
	putchar(c);
}
/**
 * print_s - print string
 * @params:variadic arguments
 * Return:none
 */
void print_s(va_list params)
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
}
