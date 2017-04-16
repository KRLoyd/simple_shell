#include "shell.h"
/**
 * main - Kristen and Jennifer's Shell
 *
 * Return: 0 (SUCCESS), -1 (FAILURE)
 */
int main(void)
{
	char *user_input;
	size_t input_size;
	struct stat stats;
	int get_res, non;
	char **args;
	char *search_res;
	list_t *linked_path;

	user_input = NULL;
	args = NULL;
	search_res = NULL;
	non = -1;
/* create linked list from PATH */
		linked_path = link_path();
		if (linked_path == NULL)
		{
			perror("Unable to create linked list from PATH");
			return (-1);
		}
/* check status of mode */
	if (fstat(STDIN_FILENO, &stats) == -1)
	{
		perror("fstat Error:\n");
		exit(EXIT_FAILURE);
	}
/* check if in non-interactive mode */
	if ((stats.st_mode & S_IFMT) == S_IFIFO)
		non = 0;
/* if interactive mode, print prompt*/
	if (non == -1)
		write(STDOUT_FILENO, PROMPT, PRSIZE);
/* START OF INFINITE LOOP */
/*get user input */
	while ((get_res = getline(&user_input, &input_size, stdin)) != -1)
	{
		if (_strncmp(user_input, "\n", 1) == 0)
			write(STDOUT_FILENO, PROMPT, PRSIZE);
		else/* (newline != 0)*/
/* split user_input into an array */
		{
			args = tokenizer(user_input);
/* search for args[0] in PATH */
			search_res = search_path(args[0], linked_path);
			if (search_res == NULL)
			{
				perror("Unable to search PATH");
				return (-1);
			}
/* Execute search_res */
			execution(search_res, args);
/* free search_res and args */
			if (_strcmp(search_res, user_input) != 0)
				free(search_res);
			free(args);
/* if interactive mode, print prompt again */
			if (non == -1)
				write(STDOUT_FILENO, PROMPT, PRSIZE);
		}
	}
/*free user_input and linked_path */
	free(user_input);
	free_linked_path(linked_path);
	return (0);
}
