#ifndef MAIN_H
#define MAIN_H
void _printf(const char *format,...);
typedef struct printer
{
char *symb;
void (*func)(va_list params);
} print_by_t;
#endif
