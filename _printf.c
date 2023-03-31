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
int init1(int state, int leng)
{
	leng++;
	putchar('%');
	state = 0;
	return (state);
}

int _printf(const char *format, ...)
{
	int i, leng = 0, up = 0, state = 0;
	va_list params;
	print_by_t pbt[] = {{"s", print_s}, {"c", print_c}};

	va_start(params, format);
	while (*format)
	{
		if (state == 0)
			if (*format == '%')
				state = 1;
			else
			{
				leng++;
				putchar(*format);
			}
		else
		{
			if (*format == '%')
				init1(state, leng);
			else
			{
				up = 0;
				for (i = 0 ; i < 2 ; i++)
					if (*format == *(pbt[i].symb))
					{
						up = 1;
						leng += pbt[i].func(params);
						state = 0;
					}
				if (up == 0)
					init(format, leng);
			}
			state = 0;
		}
	format++;
	}
	va_end(params);
return (leng);
}
