#include "shell.h"
#include <string.h>

/**
 * mysh_strlen - Get the length of a string.
 * @strW: The input string.
 *
 * Return: The length of the string.
 */
size_t mysh_strlen(const char *strW)
{
	size_t length = 0;

	while (strW[length] != '\0')
	{
		length++;
	}
	return (length);
}
