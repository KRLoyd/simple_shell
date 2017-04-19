#include "shell.h"
/**
 * execution - executes the command passed as a string
 * @str: command to execute
 * @args: array of argument strings passed to new program
 **/
void execution(char *str, char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0) /* child */
	{
		if (execve(str, args, environ) == -1)
			perror("execve error:\\n");
	}
	else /* parent */
	{
		wait(&status);
	}
}
