#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "shell.h"

/**
 * parent_childfork - Creating a child process to execute a command.
 * @buffhouse: contains command to be executed.
 * @mira_argv: Array of arguments
 */

void parent_childfork(char *buffhouse, char *const mira_argv[]);
void parent_childfork(char *buffhouse, char *const mira_argv[])
{
	pid_t child_ID;
	int i;
	int status;
	char **mira_argv_copy;
	char *full_path = get_path(buffhouse);

	if (strcmp(mira_argv[0], "exit") == 0)
	{
		if (mira_argv[1] != NULL)
		{
			write(STDERR_FILENO, "exit: too many arguments\n", 25);
			return;
		}

		exit(EXIT_SUCCESS);
	}
	else if (strcmp(mira_argv[0], "env") == 0)
	{
		program_envPTR();
		return;
	}

	full_path = get_path(buffhouse);

	if (full_path == NULL)
	{
		write(STDERR_FILENO, "Executable not found in PATH: ", 29);
		write(STDERR_FILENO, buffhouse, strlen(buffhouse));
		write(STDERR_FILENO, "\n", 1);
		free(full_path);
		return;
	}

	mira_argv_copy = malloc(sizeof(char *) * (countPtr_args(mira_argv) + 1));
	if (mira_argv_copy == NULL)
	{
		perror("Memory allocation failed\n");
		free(full_path);
		return;
	}

	for (i = 0; mira_argv[i] != NULL; i++)
	{
		mira_argv_copy[i] = strdup(mira_argv[i]);
		if (mira_argv_copy[i] == NULL)
		{
			perror("Memory allocation failed\n");
			freePtr_args(mira_argv_copy);
			free(full_path);
			return;
		}
	}

	child_ID = fork();

	if (child_ID == -1)
	{
		perror("fork failed");
		freePtr_args(mira_argv_copy);
		free(full_path);
		return;
	}

	if (child_ID == 0)
	{
		if (execve(full_path, mira_argv_copy, NULL) == -1)
		{
			perror("execve failed");
			freePtr_args(mira_argv_copy);
			free(full_path);
			return;
		}
	}
	else
	{
		wait(&status);
	}

	freePtr_args(mira_argv_copy);
	free(full_path);
}

