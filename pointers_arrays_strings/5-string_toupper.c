#include "main.h"

/**
 * string_toupper - Changes all lowercase letters to uppercase
 * @s: The string
 *
 * Return: Pointer to s
 */
char *string_toupper(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
	}
	return (s);
}
