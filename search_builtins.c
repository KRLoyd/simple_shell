fck#include "shell.h"
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
		{"exit", },
		{},
		{},
		{NULL, NULL},
	};

	i = 0;

	while (builtins[i].s != NULL)
	{
		if (_strncmp(str[0], list[i].s) == 0)
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
 * @environ: array of pointers to  environment variables
 * Return: 0 on SUCCESS, -1 on FAILURE
 */
int _env(env_t **environ)
{
	env_t *env;

	env = *environ;
	if (env == NULL)
	{ _putstring("Error printing environment variables\n");
		return (-1);
	}
	while (env != NULL)
	{
		_putstring("%s\n", *env);
		env++;
	}

	return (0);
}
