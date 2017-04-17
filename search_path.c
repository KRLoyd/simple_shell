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
<<<<<<< HEAD

	half_path = malloc(sizeof(char) * BUFSIZE);
	if (half_path == NULL)
		perror("half_path malloc\n"); return (NULL);

	full_path = malloc(sizeof(char) * BUFSIZE);
	if (full_path == NULL)
		perror("full_path malloc\n"); return (NULL);

=======
	}
>>>>>>> 8f206bd1d9ac75f0792bdac2aafd6605e3ece02b
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
