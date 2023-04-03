#include<string.h>
#include<stdarg.h>
#include<stdlib.h>
#include<stdio.h>
#include"main.h"
/**
 * _printf - same as printf
 *@format: string or the mesage to print
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
 * @leng:
 *
 */
void init1(int leng)
{
	leng++;
	putchar('%');
}

int _printf(const char *format, ...)
{
	int i, leng = 0, state = 0;
	va_list params;
	print_by_t pbt[] = {{"s", print_s}, {"c", print_c}};

	va_start(params, format);
	if (format == NULL || (strlen(format) == 1 && *format == '%'))
			return (-1);
	else
	{
	va_start(params, format);
	while (*format)
	{	if (state == 0)
			if (*format == '%')
				state = 1;
			else
			{	leng++;
				putchar(*format);
			}
		else
		{if (*format == '%')
			{	init1(leng);
				leng++;
			}
			else
			{	
				if (*format != 'c' && *format != 's')
				{	init(format, leng);
					leng += 2;
				}
				else
					for (i = 0 ; i < 2 ; i++)
					if (*format == *(pbt[i].symb))
						leng += pbt[i].func(params);
			}
			state = 0;
		}
	format++;
	}
	va_end(params);
	}
return (leng);
}
