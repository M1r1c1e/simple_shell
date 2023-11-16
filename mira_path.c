#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "shell.h"

/**
 * get_path - program function to get full command path.
 * @inputcom: The command to look for in the PATH.
 *
 * Return: full path of the command if found, or NULL.
 */

char *get_path(char *inputcom);
char *get_path(char *inputcom)
{
	int inputcomLen;
	int pathpro_toklen;
	char *pathpro_cpy;
	char *pathpro_tok;
	char *pathpro_doc;
	char *pathpro = getenv("PATH");
	struct stat pathbuf;

	if (strcmp(inputcom, "exit") == 0 || strcmp(inputcom, "env") == 0)
	{
		return (strdup(inputcom));
	}

	if (pathpro == NULL)
	{
		perror("getenv failed");
		return (NULL);
	}

	pathpro_cpy = strdup(pathpro);

	if (pathpro_cpy == NULL)
	{
		perror("strdup failed");
		return (NULL);
	}

	pathpro_tok = strtok(pathpro_cpy, ":");

	while (pathpro_tok != NULL)
	{
		inputcomLen = strlen(inputcom);
		pathpro_toklen = strlen(pathpro_tok);
		pathpro_doc = malloc(inputcomLen + pathpro_toklen + 2);

		if (pathpro_doc == NULL)
		{
			perror("Memory allocation failed\n");
			free(pathpro_cpy);
			return (NULL);
		}

		strcpy(pathpro_doc, pathpro_tok);
		strcat(pathpro_doc, "/");
		strcat(pathpro_doc, inputcom);

		if (stat(pathpro_doc, &pathbuf) == 0)
		{
			free(pathpro_cpy);
			return (pathpro_doc);
		}
		else
		{
			free(pathpro_doc);
			pathpro_tok = strtok(NULL, ":");
		}
	}

	free(pathpro_cpy);

	if (stat(inputcom, &pathbuf) == 0)
	{
		return (strdup(inputcom));
	}

	return (NULL);
}

