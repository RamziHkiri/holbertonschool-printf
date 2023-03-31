#ifndef MAIN_H
#define MAIN_H
int _printf(const char *format,...);
int print_c(va_list params);
int print_s(va_list params);

typedef struct printer
{
char *symb;
int (*func)(va_list params);
} print_by_t;
#endif
