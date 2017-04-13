#include "shell.h"
/**
 * putstring - prints a string
 * @str: string to print
 *
 */
void putstring(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}
