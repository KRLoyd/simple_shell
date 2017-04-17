#include "shell.h"
/**
 * _strncmp - compares two character strings up to n bytes
 * @s1: first string
 * @s2: second string
 * @n: number of bytes to compare
 *
 * Return: 0 (SUCCESS), -1 (FAILURE)
 */
int _strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;
	for (i = 0; s1[i] != '\0' && s2[i] != '\0' && i < n; i++)
	{
		if (s1[i] != s2[i])
		    return (-1);
	}
		return (0);
}
