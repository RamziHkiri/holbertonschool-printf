#include<stdarg.h>
#include<stdlib.h>
#include<stdio.h>
#include"main.h"
/**
 * _printf - same as printf
 *@format: string or the mesage to print
 * Return:none
 */
int _printf(const char *format, ...)
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
return (0);
}
