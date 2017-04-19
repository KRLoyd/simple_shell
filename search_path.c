#include "shell.h"
/**
 * search_path - looks for files in the current PATH
 * @str: file to search for
 * @list: PATH
 *
 * Return: filepath (SUCCESS), NULL (FAILURE)
 */
char *search_path(char *str, list_t *list)
{
	char *liststr;
	int access_res;

	liststr = malloc(sizeof(char) * BUFSIZE);
	if (liststr == NULL)
		perror("liststr malloc\n"); return (NULL);

	while (list != NULL)
	{
		clear_buff(liststr);
		liststr = _strcpy(liststr, list->str);
		liststr = _strcat(liststr, "/");
		if (liststr == NULL)
		{
			perror("Error concatenating to liststr\n");
			return (NULL);
		}
		liststr = _strcat(liststr, str);
		if (liststr == NULL)
		{
			perror("Error concatenating to liststr\n");
			return (NULL);
		}
		else
		{
			access_res = access(liststr, X_OK);
			if (access_res == 0)
			{
				return (liststr);
			}
		}
		list = list->next;
	}
	free(liststr);
	return (str);
}
