#include "shell.h"
#include <string.h>


/**
 * mysh_strcpy - Copy a string.
 * @receiver: Destination string.
 * @giver: Source string.
 *
 * Return: A pointer to the destination string.
 */
char *mysh_strcpy(char *receiver, const char *giver)
{
	char *begin = receiver;

	while ((*receiver = *giver))
	{
		receiver++;
		giver++;
	}
	return (begin);
}

/**
 * mira_strcat - Concatenate two strings.
 * @dest_str: Destination string.
 * @input: Source string.
 *
 * Return: A pointer to the destination string.
 */
char *mira_strcat(char *dest_str, const char *input)
{
	char *begin = dest_str;

	while (*dest_str)
	{
		dest_str++;
	}
	while ((*dest_str++ = *input++))
	{
		;
	}
	return (begin);
}

/**
 * mysh_strcmp - Compare two strings.
 * @sh_str1: First string.
 * @sh_str2: Second string.
 *
 * Return: 0 if strings are the same or the difference between characters.
 */
int mysh_strcmp(const char *sh_str1, const char *sh_str2)
{
	while (*sh_str1 && (*sh_str1 == *sh_str2))
	{
		sh_str1++;
		sh_str2++;
	}
	return (*(unsigned char *)sh_str1 - *(unsigned char *)sh_str2);
}

/**
 * mysh_strchr - Find the first occurrence of a character in a string.
 * @c_str: Input string.
 * @charac: Character to find.
 *
 * Return: A pointer to the first occurrence of the character,
 * or NULL if the character is not found.
 */
char *mysh_strchr(const char *c_str, int charac)
{
	while (*c_str && *c_str != charac)
		c_str++;
	if (*c_str == charac)
	return ((char *)c_str);
	return (NULL);
}

/**
 * mysh_strncpy - Copy a specific number of characters
 * from one string to another.
 * @output: Destination string.
 * @origin: Source string.
 * @num: Number of characters to copy.
 *
 * Return: A pointer to the destination string.
 */
char *mysh_strncpy(char *output, const char *origin, size_t num)
{
	char *begin1 = output;

	while (num-- && (*output++ = *origin++))
	{
		;
	}
	return (begin1);
}

