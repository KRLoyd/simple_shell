#include "shell.h"
/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: first element of the list
 * @str: string to add to node
 *
 * Return: pointer to the added node (SUCCESS), NULL (FAILURE)
 */
list_t *add_node_end(list_t **head, char *str)
{
	list_t *new_last;
	list_t *temp;

	temp = *head;
	new_last = malloc(sizeof(list_t));
	if (new_last == NULL)
	{
		perror("Couldn't malloc for new_last\n");
		return (NULL);
	}
	new_last->str = str;
	if (new_last->str == NULL)
	{
		free(new_last);
		return (NULL);
	}
	new_last->len = strlen_rec(str);
	new_last->next = NULL;
	if (*head == NULL)
	{
		*head = new_last;
		return (new_last);
	}
	while (temp->next != NULL)
		temp = temp->next;
        temp->next = new_last;
	return (new_last);
}
