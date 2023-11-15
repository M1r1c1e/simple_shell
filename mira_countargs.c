#include <stdlib.h>
#include <string.h>

/**
 * countPtr_args - Counting number of pointers in an array of strings.
 * @args: An array of strings.
 *
 * Return: The number of pointers in the array.
 */
int countPtr_args(char *const args[])
{
	int countPtr = 0;

	while (args[countPtr] != NULL)
	{
		countPtr++;
	}

	return (countPtr);
}

/**
 * freePtr_args - Freeing the memory allocated
 * @args: The strings.
 */
void freePtr_args(char *args[])
{
	int i;

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}

	free(args);
}

