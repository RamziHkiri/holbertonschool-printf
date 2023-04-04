_PRINTF() PROJECT

DESCRIPTION:

	This is an interpretation of the original printf function. It intends to satisfy a given list of conditions which the standard library printf is able to do.
Our _printf can:
	*print integer decimal with the specifier 'd'
	*print integer with the specifier 'i'
	*print caracter with the specifier 'c'
	*print string with the specifier 's'
	*print the %

	prototype: int _printf(const char *format, ...);

FORMAT SPECIFIER:
	
	A format specifier is marked with the percent symbol %. To print some argumets you should use the percent followed by the specifier character to specify  which type of data you want to print.

EXEMPLES:
	Printing character "%c":
		_printf ("%c", 'H');
		output: H
	Printing string "%s":
                _printf ("%s", 'Holberton school tunis');
                output: Holberton school tunis
	Printing integer "%d":
                _printf ("%d", 5424);
                output: 5424

FUNCTIONS USED:

	int print_c(char c)
		 This function gets a variadic arguments list, traverses the list, prints a character and return the length 1

	int print_s (va_list args)
		This function gets a variadic arguments list, traverses the list, prints each character of char type and returns the length of the character.

	int _print_d (va_list args)
This function gets a variadic arguments list, traverses the list, prints each number of int type and returns the length of the integer.

AUTHOR
This content is created by RAMZI HKIRI 
		date: 04/04/2023.


