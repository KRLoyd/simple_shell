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

	head = NULL;
	to_link = _getenv("PATH");
	if (to_link == NULL)
	{
		putstring("Unable to link path\n"); return (NULL);
	}
	dir = strtok(to_link, ":");
	while (to_link != NULL)
	{
		if (dir == NULL)
			break;
		else /* dir != NULL */
		{
			add_result = add_node_end(&head, dir);
			if (add_result == NULL)
			{
				putstring("Unable to add node\n"); return (NULL);
			}
		}
		dir = strtok(NULL, ":");
	}
	free(add_result);
	return (head);
}
