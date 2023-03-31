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
	int i, leng, l, up, state = 0;
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
				leng++;
				putchar(*format);
			}
		}
		else
		{
			if (*format == '%')
			{
				leng++;
				putchar('%');
				state = 0;
			}

			else
			{
				up = 0;
				for (i = 0 ; i < 2 ; i++)
					if (*format == *(pbt[i].symb))
					{
						up = 1;
						l = pbt[i].func(params);
						leng += l;
						state = 0;
					}
				if (up == 0)
				{
					putchar('%');
					putchar(*format);
					l += 2;
				}
			}
			state = 0;
		}
	format++;
	}
return (leng);
}
