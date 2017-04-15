#include "shell.h"
/**
 * execution - executes the command passed as a string
 * @str: command to execute
 **/
void execution(char *str, char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0) /* child */
	{
		printf("child created\n");
		if (execve(str, args, NULL) == -1)
			perror("execve error:\\n");
	}
	else /* parent */
	{
		wait(&status);
		printf("Child terminated\n");
	}
}
