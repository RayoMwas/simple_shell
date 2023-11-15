#include "main.h"
/**
 * execute_command - executes command with the help of execve
 * @command: pointer to a char
 *
 * Return: Always 0
 */
int execute_command(char *command)
{
	pid_t pid;
	int status;
	char *token;
	char *args[100];
	int arg_count = 0;

	token = strtok(command, " ");
	while (token != NULL)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " ");
	}
	args[arg_count] = NULL; /* NULL-terminate the array */
	pid = fork();
	if (pid == 0)
	{
		/* In child process */
		if (execve(args[0], args, NULL) == -1)
		{
			perror("./hsh");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror(args[0]);
	}
	else
	{
		do {
			pid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (0);
}
