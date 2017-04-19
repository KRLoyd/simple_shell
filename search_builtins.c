#include "shell.h"
/**
 * search_builtins - search for builtins from user input
 * @str: name of builtin for which to search
 * Return: 0 on SUCCESS
 */
int search_builtins(char *str)
{
	int i;

	builtins_t builtins[] = {
		{"env", _env },
		{"exit", execute_exit},
		{NULL, NULL},
	};

	i = 0;

	while (builtins[i].s != NULL)
	{
		if (_strncmp(str, builtins[i].s, strlen_rec(str)) == 0)
		{
			builtins[i].fcn(str);
			return (0);
		}
		i++;
	}
	return (-1);
}


/**
 * _env - prints environment variable
 * Return: Always 0
 */
int _env(void)
{
	unsigned int i;

	i = 0;
	while (environ[i] != NULL)
	{
		putstring(environ[i]);
		_putchar('\n');
		i++;
	}
	return (0);
}

/**
 * execute_exit - function to exit with a status
 * Return: 0
 */

int execute_exit(void)
{
	exit(0);
}
