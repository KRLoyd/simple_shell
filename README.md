# Simple <a href="https://www.holbertonschool.com/">Holberton</a> Shell
A simple UNIX command line interpreter that reads and implements basic commands from user input. Simple Shell project requires students to build a simple shell with a restriction of allowed functions. We use our knowledge in C so far to implement and create functions and programs necessary to build a working simple shell.  

## Installation
All files compiled on Ubuntu 14.04 LTS with `gcc 4.8.4`

**Clone repo**:
`$ git clone https://github.com/KRLoyd/simple_shell.git`

**Compile**
`$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh `

**Run simple_shell**:
`$ ./hsh`

A prompt will follow upon running `./hsh` <br />
Simple_shell is ready to take commands: <br />
`$  `

##Usage
```
$
```

## Allowed Functions
```
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
fork (man 2 fork)
free (man 3 free)
fstat (man 2 fstat)
getcwd (man 3 getcwd)
getline (man 3 getline)
kill (man 2 kill)
lstat (man 2 lstat)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (man 2 stat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)
_exit (man 2 _exit)
```

## File Descriptions
[shell.h](shell.h) - header file containing function prototypes, struct definitions, macros, standard libraries.

[simple_shell](simple_shell.c) - simple shell program that 1) checks if in interactice/noninteractice mode 2) prints prompt and waits for user input 3) splits user input into an array 4) prints prompt again if in interactice mode

[execution](execution.c) - executes the command passed as a string

**PATH**
- [search_path](search_path.c) - looks for files in the current PATH. Returns file path on success, NULL on failure
- [link_path](link_path.c) - creates a linked list of directories in PATH. Returns pointer to first element of linked list.
- [free_linked_path](free_linked_path.c) - frees the linked path

**BUILTINS**
[search_builtins](search_builtins.c) - searchs for builtins from user input
- `_env` - prints environment variable
- `execute_exit` - exits function

**HELPER FUNCTIONS**
- [add_node_end](add_node_end.c) - adds a new node at the end of a list_t list. Returns pointer to added node, or NULL
- [clear_buff](clear_buff.c) - sets buffer to '\0'
- [_putchar](_putchar.c) - writes character to stdout
- [putctring](putstring.c) - prints a string
- [strfcns](strfcns.c) - helper string functions:
  `_strcat` - concatenates two strings. Returns pointer to resulting string.
  `_strcmp` - compares two strings. Returns (-) if s1 < s2, (0) if s1 > s2, 0 if s1 = s2
  `_strcpy` - copies string from src to dest. Returns pointer to dest
  `_strncmp` - compares two character strings up to n bytes. Return 0-success, -1-failure
  `strlen_rec` - finds and returns length of a string.
- [tokenizer](tokenizer.c) - splits a character string into an array of tokens