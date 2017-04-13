#include "shell.h"
/**
 * _getenv - get an environment variable
 * @name: environment variable to look for
 *
 * Return: pointer to the variable (SUCCESS), NULL (FAILURE)
 */
extern char **environ;
char *_getenv(const char *name)
{
	char *env_value;
	char *variable;
	unsigned int i, len;
	int compare;

	i = 0;
	while (environ[i] != NULL)
	{
		variable = environ[i];
		len = strlen_rec((char *)name);
		compare = strncmp((char *)name, variable, len);
		if (compare == 0)
		{
			env_value = strtok(variable, "=");
			env_value = strtok(NULL, " ");
			return (env_value);
		}
		i++;
	}
	return (NULL);
}
