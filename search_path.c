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
	char *half_path;
	char *full_path;
	char *liststr;
	int access_res;

	liststr = malloc(sizeof(char) * BUFSIZE);
	if (liststr == NULL)
		perror("liststr malloc\n"); return (NULL);

	half_path = malloc(sizeof(char) * BUFSIZE);
	if (half_path == NULL)
		perror("half_path malloc\n"); return (NULL);

	full_path = malloc(sizeof(char) * BUFSIZE);
	if (full_path == NULL)
		perror("full_path malloc\n"); return (NULL);

	while (list != NULL)
	{
		clear_buff(full_path);
		clear_buff(half_path);
		clear_buff(liststr);
		liststr = _strcpy(liststr, list->str);
		half_path = _strcat(liststr, "/");
		if (half_path == NULL)
		{
			putstring("Error concatenating to half_path\n");
			return (NULL);
		}
		full_path = _strcat(half_path, str);
		printf("full_path: %s\n", full_path);
		if (full_path == NULL)
		{
			putstring("Error concatenating to full_path\n");
			return (NULL);
		}
		else
		{
			access_res = access(full_path, X_OK);
			if (access_res == 0)
			{
				return (full_path);
			}
		}
		list = list->next;
	}
	return (str);
}
