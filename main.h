#ifndef MAIN_H
#define MAIN_H
int _printf(const char *format,...);
void print_c(va_list params);
void print_s(va_list params);

typedef struct printer
{
char *symb;
void (*func)(va_list params);
} print_by_t;
#endif
