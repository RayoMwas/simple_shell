#include "main.h"
/**
 * token - tokenizes the strings
 *
 * Return: 0 on success
 */
int token(void)
{
	char *token;
	char *delim;

	delim = " ";
	token = strtok(command, delim);
	while (token)
	{
		token = strtok(NULL, delim);
	}
	return (0);
}
