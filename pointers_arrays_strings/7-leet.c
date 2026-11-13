#include "main.h"

/**
 * leet - Encodes a string into 1337
 * @s: The string
 *
 * Return: Pointer to s
 */
char *leet(char *s)
{
	char *from = "aAeEoOtTlL";
	char *to = "4433007711";
	int i, j;

	for (i = 0; s[i]; i++)
	{
		for (j = 0; from[j]; j++)
		{
			if (s[i] == from[j])
				s[i] = to[j];
		}
	}
	return (s);
}
