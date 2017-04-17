#include "shell.h"
/**
 * free_dblpt_char - frees a char **
 * @to_free: char ** to free
 */
void free_dblpt_char(char **to_free)
{
	int i;

	for (i = 0; to_free[i] != NULL && *to_free != NULL; i++)
		free(to_free[i]);
	free(to_free);
}
