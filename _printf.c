#include<string.h>
#include<stdarg.h>
#include<stdlib.h>
#include<stdio.h>
#include"main.h"
/**
 * init - same as printf
 *@format: string or the mesage to print
 *@leng:lenght of the format
 * Return:none
 */

void init(const char *format, int leng)
{
	putchar('%');
	putchar(*format);
	leng += 2;
}
/**
 * init1 - initialize some param
 * @leng:length of the format
 *
 */
void init1(int leng)
{
	leng++;
	putchar('%');
}
/**
 * test - test the occurence of the specifier or no
 * @format: string to test
 * @params:va_list
 * Return:none
 */
int test(const char *format, va_list params)
{
	int i, leng = 0;
	print_by_t pbt[] = {{"s", print_s}, {"c", print_c}, {"d", print_d}, {"i",print_d}};

	if (*format != 'c' && *format != 's')
	{
		init(format, leng);
		leng += 2;
	}
	else
		for (i = 0 ; i < 2 ; i++)
			if (*format == *(pbt[i].symb))
			leng = pbt[i].func(params);
	return (leng);
}
/**
 * _printf - same as printf
 *@format: string or the mesage to print
 * Return:none
 */

int _printf(const char *format, ...)
{
	int leng = 0, state = 0;
	va_list params;

	if (format == NULL || (strlen(format) == 1 && *format == '%'))
	{
		return (-1);
	}
	else
	{
	va_start(params, format);
	while (*format)
	{
		if (state == 0)
			if (*format == '%')
				state = 1;
			else
			{	leng++;
				putchar(*format);
			}
		else
		{
			if (*format == '%')
			{	init1(leng);
				leng++;
			}
			else
				leng += test(format, params);
			state = 0;
		}
	format++;
	}
	va_end(params);
	}
return (leng);
}
