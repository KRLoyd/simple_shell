# Simple shell project for <a href="https://www.holbertonschool.com/">Holberton School</a>.

A simple UNIX command line interpreter(in **C** ) that reads and implements basic commands from user input.

##Installation
All files compiled on Ubuntu 14.04 LTS with `gcc 4.8.4`

**Clone repo**:
`$ git clone https://github.com/KRLoyd/simple_shell.git`

**Run simple_shell**:
`./simple_shell`

A prompt will follow upon running `./simple_shell`. Simple_shell is ready to take commands.
`$`


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
**BUILTINS**


**HELPER FUNCTIONS**
- [_putchar](_putchar.c) - writes character to stdout
- [putctring](putstring.c) - prints a string
- [strlen_rec](strlen_rec.c) - finds the length of a string
- [tokenizer](tokenizer.c) - splits a character string into an array of tokens

##Usage
