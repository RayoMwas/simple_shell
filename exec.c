#include "main.h"
/**
 * exec - executes commands
 *
 * Return: 0 on success
 */
int exec(void)
{
	char **args;
	int status;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("./hsh");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		args = malloc(2 * sizeof(char *));
		if (args == NULL)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
		args[0] = command;
		args[1] = NULL;
		if (execve(command, args, environ) == -1)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
		free(args);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	return (0);
}
