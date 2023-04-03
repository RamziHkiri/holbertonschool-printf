#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"
/**
 * print_c - print character
 * @params:variadic arguments
 * Return:length of the result
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
/**
 * print_d - print integer
 * @params: variadic argumets
 * Return:length of the result
 */
int print_d(va_list list)
{
	int num1 = va_arg(list, int), num2;
	int div = 1, i = 0;

	if (num1 < 0)
	{
		_putchar('-');
		i++;
		num1 *= -1;
	}
	num2 = num1;
	while (num2 > 9)
	{
		div *= 10;
		num2 = num2 / 10;
	}
	while (div >= 1)
	{
		num2 = num1 % div;
		num1 /= div;
		_putchar(num1 + '0');
		num1 = num2;
		div /= 10;
		i++;
	}
	return (i);
}
