#include "main.h"

/**
 * _strlen - Returns the length of a string
 * @s: The string
 *
 * Return: The length of s
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}
