#include "shell.h"
/**
 * main - create a linked list of directories in PATH
 *
 * Return: pointer to the first element in the list (SUCCESS), NULL (FAILURE)
 */
list_t *link_path(void)
{
	char *to_link;
	char *dir;
	list_t *head;
	list_t *add_result;
	char *copy_src;

	to_link = malloc(sizeof(char) * BUFSIZE);
	if (to_link == NULL)
	{
		perror("Unable to malloc space for to_link");
		return (NULL);
	}
	head = NULL;
	copy_src = _getenv("PATH");
	to_link = _strcpy(to_link, copy_src);
	if (to_link == NULL)
	{
		perror("Unable to link path\n"); return (NULL);
	}
	dir = strtok(to_link, ":");
	while (dir != NULL)
	{
		if (dir == NULL)
			break;
		else /* dir != NULL */
		{
			add_result = add_node_end(&head, dir);
			if (add_result == NULL)
			{
				perror("Unable to add node\n"); free(copy_src);return (NULL);
			}
		}
		dir = strtok(NULL, ":\n");
	}
	free(copy_src);
	return (head);
}
