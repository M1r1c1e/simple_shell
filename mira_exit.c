#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * proexit_fig - function that handles the "exit" command
 * @mira_argv: The array of arguments for the command.
 */
void proexit_fig(char **mira_argv)
{
	int statusPTR;
	int i;

	if (mira_argv == NULL)
	{
		write(STDOUT_FILENO, "Shell exiting.\n", 15);
		return;
	}

	if (mira_argv[0] != NULL && strcmp(mira_argv[0], "exit") == 0)
	{
		for (i = 0; mira_argv[i] != NULL; i++)
		{
			free(mira_argv[i]);
		}
		free(mira_argv);

		if (mira_argv[1] != NULL)
		{
			statusPTR = atoi(mira_argv[1]);
		}
		else
		{
			statusPTR = 0;
		}

		write(STDOUT_FILENO, "Shell exiting.\n", 15);
		_exit(statusPTR);
	}

}

