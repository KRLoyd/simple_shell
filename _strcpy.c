#include "shell.h"
/**
 * _strcpy - copy string from src to dest
 * @dest: first string, has buffer
 * @src: second string, to be copied
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	unsigned int i, len;

	len = strlen_rec(src);
	for (i = 0; i < len; i++)
		dest[i] = src[i];
	dest[len] = '\0';
	return ((char *)dest);
}
