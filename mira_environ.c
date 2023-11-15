#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * program_envPTR - Printing the environment variables
 */
void program_envPTR(void)
{
	int i;
	char **envPTR = environ;

	for (i = 0; envPTR[i] != NULL; i++)
	{
		write(STDOUT_FILENO, envPTR[i], strlen(envPTR[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}

