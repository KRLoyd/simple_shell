#include "shell.h"
/**
 * er_simple_shell - error messages for simple_shell failures
 * @n: assigned error number
 * Return: -1
 */
int er_simple_shell(int n)
{
	switch (n)
	{
	case 01:
		perror("Unable to create linked list from PATH");
		break;

	case 02:
		perror("fstat Error:\n");
		exit(EXIT_FAILURE);

	case 03:
		perror("Unable to search PATH");
		break;
	}

	return (-1);
}

/**
 * er_search_path - error messages for search path failure
 * @b: assigned error number
 * Return: NULL
 */
char *er_search_path(int b)
{
	switch (b)
	{
	case 001:
		perror("Error concatenating to liststr\n");
		break;

	case 002:
		perror("liststr malloc\n");
		break;
	}
	return (NULL);
}
