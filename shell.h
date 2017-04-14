#ifndef __JKSHELL__
#define __JKSHELL__
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#define ENV extern char **environ
#define PROMPT "($) "
#define BUFSIZE 1024

extern char **environ;
/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;
list_t *add_node_end(list_t **head, char *str);
void clear_buff(char *buffer);
char *_getenv(const char *name);
list_t *link_path(void);
int _putchar(char c);
void putstring(char *str);
char *search_path(char *str, list_t *list);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int strlen_rec(char *s);
int _strncmp(char *s1, char *s2, unsigned int n);
char **tokenizer(char *s);
#endif /* __JKSHELL__ */
