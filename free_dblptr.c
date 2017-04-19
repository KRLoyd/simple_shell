#include "shell.h"
/**
 * free_dblptr - frees a double pointer
 * @array: double pointer to free
 * @len: length of the double pointer
 */
void free_dblptr(char **array, unsigned int len)
{
	unsigned int i;

	for (i = 0; i < len; i++)
	{
		free(array[i]);
	}
	free(array);
}
