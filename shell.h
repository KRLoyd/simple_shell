#ifndef __JKSHELL__
#define __JKSHELL__
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
<<<<<<< HEAD
#define ENV extern char **environ
=======
#include <sys/wait.h>
>>>>>>> 8f206bd1d9ac75f0792bdac2aafd6605e3ece02b
#define PROMPT "($) "
#define PRSIZE strlen_rec(PROMPT)
#define BUFSIZE 1024
<<<<<<< HEAD

extern char **environ;
=======
>>>>>>> 8f206bd1d9ac75f0792bdac2aafd6605e3ece02b
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
/**
 * struct builtins_s - struct for builtins
 * @s: pointer to user-inputed commands
 * @fcn: pointer to corresponding command function
 
 */
typedef struct builtins_s
{
	char *s;
	int (*fcn)();
} builtins_t;
extern char **environ;
list_t *add_node_end(list_t **head, char *str);
void clear_buff(char *buffer);
char **copy_env(char **env_copy, unsigned int env_len);
int _env(void);
int execute_exit(void);
void execution(char *str, char **args);
void free_dblptr(char **array, unsigned int len);
void free_linked_path(list_t *list);
char *_getenv(const char *name);
list_t *link_env(void);
list_t *link_path(void);
int _putchar(char c);
void putstring(char *str);
int search_builtins(char *str);
char *search_path(char *str, list_t *list);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int strlen_rec(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, unsigned int n);
char **tokenizer(char *s);
#endif /* __JKSHELL__ */
