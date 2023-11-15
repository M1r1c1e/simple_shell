#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shell.h"

/**
 * main - shell program logic.
 *
 * Return: Always 0.
 */
int main(void)
{
	int i;
	char **inputARG;

	while (1)
	{
		inputARG = obtain_tokens();

		if (inputARG == NULL)
		{
			write(STDOUT_FILENO, "Shell exiting.\n", 15);
			break;
		}

		proexit_fig(inputARG);

		parent_childfork(inputARG[0], inputARG);

		for (i = 0; inputARG[i] != NULL; i++)
		{
			free(inputARG[i]);
		}
		free(inputARG);
	}

	return (0);
}

