#ifndef __JKSHELL__
#define __JKSHELL__
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#define PROMPT "($) "
#define BUFSIZE 1024
int _putchar(char c);
void putstring(char *str);
int strlen_rec(char *s);
char **tokenizer(char *s);
#endif /* __JKSHELL__ */
