#include "shell.h"
/**
 * main - Kristen and Jennifer's Shell
 *
 * Return: 0 (SUCCESS), -1 (FAILURE)
 */
int main(void)
{
	char *user_in, *search_res;
	size_t input_size;
	int builtin_res, non;
	char **args;
	list_t *linked_path;
	struct stat stats;

	user_in = search_res = NULL;
	args = NULL;
	non = 0;
	linked_path = link_path();
	null_check(linked_path);
	if (fstat(STDIN_FILENO, &stats) == -1)
	{perror("fstat Error"); exit(EXIT_FAILURE); }
	if ((stats.st_mode & S_IFMT) == S_IFIFO)
		non = 1;
	if (non == 0)
		write(STDOUT_FILENO, PROMPT, PRSIZE);
	while (getline(&user_in, &input_size, stdin) != -1)
	{
		if (_strncmp(user_in, "\n", 1) == 0)
			write(STDOUT_FILENO, PROMPT, PRSIZE);
		else/* (newline != 0)*/
		{
			args = tokenizer(user_in);
			builtin_res = search_builtins(args[0]);
			if (builtin_res == -1)
			{
				search_res = search_path(args[0], linked_path);
				search_check(search_res);
				execution(search_res, args);
				if (_strcmp(search_res, user_in) != 0)
					free(search_res);
			}
			free(args);
			if (non == 0)
				write(STDOUT_FILENO, PROMPT, PRSIZE);
		}
	} /* END OF INTINITE LOOP */
	free(user_in); free_linked_path(linked_path); return (0);
}
/**
 * null_check - check if list_t list is NULL
 * @s: list to check
 *
 * Return: -1
 */
int null_check(list_t *s)
{
	if (s == NULL)
		perror("Unable to create linked list from PATH");
	return (-1);
}
/**
 * search_checker - check if char * is NULL
 * @str: char * to check
 *
 * Return: 0 if not NULL, -1 if NULL
 */
int search_check(char *str)
{
	if (str == NULL)
	{
		perror("Unable to search PATH");
		return (-1);
	}
	return (0);
}
