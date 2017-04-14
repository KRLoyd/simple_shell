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
	int i;
	char *search_res;
	list_t *linked_path;

	user_input = NULL;
	non = 0;

	if (fstat(STDIN_FILENO, &stats) == -1)
	{
		perror("fstat Error:\n");
		exit(EXIT_FAILURE);
	}
/* check if in non-interactive mode */
	switch (stats.st_mode & S_IFMT)
	{
	case S_IFIFO:
		non = 1;
		break;
	}
/* if interactive mode, print prompt*/
	if (non == 0)
	{
		write(STDOUT_FILENO, PROMPT, strlen_rec(PROMPT));
	}
/* get user input */
	while ((get_res = getline(&user_input, &input_size, stdin)) != -1)
	{
		if (get_res < 0)
			break;
/* split user_input into an array */
		args = tokenizer(user_input);
		for (i = 0; args[i] != NULL; i++)
			printf("args[%d]: %s\n", i, args[i]);
/* create linked list from PATH */
		linked_path = link_path();
		if (linked_path == NULL)
		{
			putstring("Unable to create linked list from PATH");
			return (-1);
		}
/* search for args[0] in PATH */
		search_res = search_path(args[0], linked_path);
		if (search_res == NULL)
		{
			putstring("Unable to search PATH");
			return (-1);
		}
		printf("search_res: %s\n", search_res);
/* if interactive mode, print prompt again */
		if (non == 0)
			write(STDOUT_FILENO, PROMPT, strlen_rec(PROMPT));
	}
	free(user_input); return (0);
}
