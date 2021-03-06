#include "shell.h"
/**
 * _strcat - concatenates 2 strings
 * @dest: string to be added to
 * @src: string to add to dest
 *
 * Return: pointer to resulting string
 */
char *_strcat(char *dest, char *src)
{
	unsigned int i, j, len;

	i = 0;
	len = strlen_rec(dest);
	for (i = 0, j = len; src[i] != '\0'; i++, j++)
		dest[j] = src[i];
	if (dest[j] != '\0')
		dest[j] = '\0';
	return ((char *)dest);
}

/**
 * _strcmp - compare two strings
 * @s1: first string, ends in '\0'
 * @s2: second string, ends in '\n'
 *
 * Return: negative if s1 < s2, positive if s1 > s2, 0 if s1 = s2
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\n'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

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

	len = strlen_rec(src) + 1;
	if (len >= (BUFSIZE - 2))
	{
		free(dest);
		dest = malloc(sizeof(char) * (BUFSIZE * 2));
		if (dest == NULL)
		{
			perror("Unable to malloc space for dest");
			return (NULL);
		}
	}
	for (i = 0; i < len - 1; i++)
	{
		dest[i] = src[i];
	}
	dest[len - 1] = '\0';
	return ((char *)dest);
}

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

/**
 * strlen_rec - find the length of a string
 * @s: string to evaluate
 *
 * Return: length of s
 */
int strlen_rec(char *s)
{
	unsigned int i;

	if (s == NULL)
		return (0);
	if (*s == '\0')
		return (0);
	i = (strlen_rec(s + 1));
	return (i + 1);
}
