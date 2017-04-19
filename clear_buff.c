#include "shell.h"
/**
 * clear_buff - sets buffer to '\0'
 * @buffer: pointer to memory buffer
 */
void clear_buff(char *buffer)
{
	int i;

	for (i = 0; i < BUFSIZE; i++)
		buffer[i] = '\0';
}
