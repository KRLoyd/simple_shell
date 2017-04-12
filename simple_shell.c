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

/* print our prompt */
	while (1)
	{
		write(STDOUT_FILENO, PROMPT, strlen_rec(PROMPT));
/* get user input */
		if (getline(&user_input, &input_size, stdin) == -1)
		{
			perror("getline Error:\n");
			return (-1);
		}
	}
	return (0);
}
