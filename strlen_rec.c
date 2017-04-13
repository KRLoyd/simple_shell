#include "shell.h"
/**
 * strlen_rec - find the length of a string
 * @s: string to evaluate
 *
 * Return: length of s
 */
int strlen_rec(char *s)
{
	unsigned int i;

	if (*s == '\0')
		return (0);
	i = (strlen_rec(s + 1));
	return (i + 1);
}
