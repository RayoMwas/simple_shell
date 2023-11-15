#include "main.h"
/**
 * printEnvironment - prints the current environment
 *
 * Return: Always 0
 */
int printEnvironment(void)
{
	unsigned int i;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
