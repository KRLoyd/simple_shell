#include "shell.h"
/**
 * free_linked_path - frees the linked path
 * @list: linked list_t list to free
 *
 */
void free_linked_path(list_t *list)
{
	list_t *temp;


	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp->str);
		free(temp);
	}
	free(list);
}
