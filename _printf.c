#include<stdarg.h>
#include<stdlib.h>
#include<stdio.h>
#include"main.h"
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
/**
 * _printf - same as printf
 *@format: string or the mesage to print
 * Return:none
 */
void _printf(const char *format, ...)
{
	int i, state = 0;
	va_list params;
	print_by_t pbt[] = {
		{"s", print_s},
		{"c", print_c}
	};
	va_start(params, format);
	while (*format)
	{
		if (state == 0)
		{
			if (*format == '%')
			{
				state = 1;
			}
			else
			{
				putchar(*format);
			}
		}
		else
		{
			if (*format == '%')
			{
				putchar('%');
				state = 0;
			}
			else
			{
				for (i = 0 ; i < 2 ; i++)
					if (*format == *(pbt[i].symb))
					{
						pbt[i].func(params);
						state = 0;
					}
			}
		}
	format++;
	}
	putchar('\n');
}
