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
	case S_IFIFO: non = 1;
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
/* if interactive mode, print prompt again */
		if (non == 0)
			write(STDOUT_FILENO, PROMPT, strlen_rec(PROMPT));
		if (non == 1)
			write(STDOUT_FILENO, PROMPT2, strlen_rec(PROMPT2));
	}
	free(user_input);
	return (0);
}
