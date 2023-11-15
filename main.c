#include "main.h"
#include <stdio.h>
char *command = NULL;
/**
 * main - prints the prompt for user input
 *
 * Return: 0 on success
 */
int main(void)
{
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf("($) ");
		read = getline(&command, &len, stdin);
		if (read == -1)
		{
			break;
		}
		if (command[read - 1] == '\n')
		{
			command[read - 1] = '\0';
		}
		if (strlen(command) == 0)
		{
			continue;
		}
		if (strcmp(command, "exit") == 0)
		{
			exit(EXIT_SUCCESS);
		}
		if (strcmp(command, "env") == 0)
		{
			printEnvironment();
		}
		exec();
	}
	free(command);
	return (0);
}
