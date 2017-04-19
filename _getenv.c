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
	char **env_copy;
	char *env_value;
	char *variable;
	char *path;
	unsigned int i, env_len, len, path_len;
	int compare;

	env_copy = NULL;

	env_len = 0;
	while (environ[env_len] != NULL)
		env_len++;
	env_len++;
	env_copy = copy_env(env_copy, env_len);
	i = 0;
	len = strlen_rec((char *)name);
	while (env_copy[i] != NULL)
	{
		variable = env_copy[i];
		compare = _strncmp((char *)name, variable, len);
		if (compare == 0)
		{
			env_value = strtok(variable, "=");
			env_value = strtok(NULL, "\n");
			if (env_value == NULL)
				return (NULL);
			path_len = strlen_rec(env_value);
			path = malloc(sizeof(char) * path_len + 1);
			if (path == NULL)
			{
				perror("Unable to malloc space for path");
				return (NULL);
			}
			path = _strcpy(path, env_value);
			free_dblptr(env_copy, env_len);
			return (path);
		}
		i++;
	}
	free_dblptr(env_copy, env_len);
	return (NULL);
}

/**
 * copy_env - copies environment variable
 * @env_copy: pointer to copy of environment variable
 * @env_len: number of variables in environment
 *
 * Return: double pointer to copy of environment variable
 */
char **copy_env(char **env_copy, unsigned int env_len)
{
	char *variable;
	unsigned int i, var_len;

	env_copy = malloc(sizeof(char **) * (env_len));
	if (env_copy == NULL)
	{
		perror("Unable to malloc space for env_copy");
		return (NULL);
	}

	for (i = 0; i < env_len; i++)
	{
		variable = environ[i];
		var_len = strlen_rec(variable) + 1;
		env_copy[i] = malloc(sizeof(char) * var_len);
		if (env_copy[i] == NULL)
		{
			perror("Unable to malloc space for env_copy[i]");

			return (NULL);
		}
		env_copy[i] = _strcpy(env_copy[i], environ[i]);
	}
	return (env_copy);
}
