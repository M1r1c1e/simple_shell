#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shell.h"

/**
 * obtain_tokens - Obtaining tokens from user input.
 *
 * Return: program array of tokens.
 */
char **obtain_tokens();
char **obtain_tokens()
{
	int idx;
	int no_tok = 0;
	char **mira_argv = NULL;
	char *buffhouse = NULL;
	char *clone_buffhouse;
	char *bufftok;
	const char *B_delim = " \n";
	size_t size_buf = 0;
	ssize_t no_char;

	while (1)
	{
		write(STDOUT_FILENO, "#$ ", 3);
		no_char = getline(&buffhouse, &size_buf, stdin);

		if (no_char == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			return (NULL);
		}

		if (buffhouse[no_char - 1] == '\n')
		{
			buffhouse[no_char - 1] = '\0';
		}

		clone_buffhouse = strdup(buffhouse);
		if (clone_buffhouse == NULL)
		{
			perror("Memory allocation failed\n");
			return (NULL);
		}

		bufftok = strtok(buffhouse, B_delim);

		while (bufftok != NULL)
		{
			no_tok++;
			bufftok = strtok(NULL, B_delim);
		}

		mira_argv = (char **)malloc(sizeof(char *) * (no_tok + 1));
		if (mira_argv == NULL)
		{
			perror("Memory allocation failed\n");
			return (NULL);
		}

		bufftok = strtok(clone_buffhouse, B_delim);

		for (idx = 0; bufftok != NULL; idx++)
		{
			mira_argv[idx] = strdup(bufftok);

			bufftok = strtok(NULL, B_delim);
		}

		parent_childfork(buffhouse, mira_argv);

		for (idx = 0; idx < no_tok; idx++)
		{
			free(mira_argv[idx]);
		}

		free(mira_argv);
		free(clone_buffhouse);
	}

	free(buffhouse);
	return (mira_argv);
}

