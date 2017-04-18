#include "shell.h"
/**
 * tokenizer - split a character string into an array of tokens
 *@s: string to split into tokens
 *
 * Return: pointer to the array (SUCCESS), NULL (FAILURE)
 */
char **tokenizer(char *s)
{
	int i, j;
	char *token;
	char **av;
	char *delim;

	i = 0;
	delim = " \t\n\r\"";

	av = malloc(sizeof(char) * BUFSIZE);
	if (av == NULL)
	{
		perror("Error: Could not malloc space for tokens\n");
		return (NULL);
	}
	token = strtok(s, delim);
	for (i = 0; token != NULL; i++)
	{
		for (j = 0; j < strlen_rec(token); j++)
			;
		if (token[j - 1] == '\n')
			token[j - 1] = '\0';
		av[i] = token;
		token = strtok(NULL, delim);
	}
	av[i] = NULL;
	return (av);
}
