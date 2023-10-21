#include "shell.h"

/**
 * _strncpy - Copy a string with a limit
 * @dest: Destination buffer
 * @src: Source string
 * @n: Maximum number of characters to copy
 *
 * Return: Pointer to the destination buffer
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;
	char *s = dest;

	for (i = 0; src[i] && i < n; i++)
		dest[i] = src[i];

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (s);
}

/**
 * _strncat - Concatenate two strings with a limit
 * @dest: Destination string
 * @src: Source string
 * @n: Maximum number of characters to append from src
 *
 * Return: Pointer to the destination string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	for (i = 0; dest[i]; i++)
		;

	for (j = 0; src[j] && j < n; j++)
		;

	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = '\0';

	return (s);
}

/**
 * _strchr - Locate a character in a string
 * @s: The string to search
 * @c: The character to find
 *
 * Return: Pointer to the first
 * occurrence of the character in the string, or NULL
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++);

	return (NULL);
}

