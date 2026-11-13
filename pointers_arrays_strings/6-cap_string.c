#include "main.h"

/**
 * cap_string - Capitalizes all words of a string
 * @s: The string
 *
 * Return: Pointer to s
 */
char *cap_string(char *s)
{
	char *sep = " \t\n,;.!?\"(){}";
	int i, j, new_word = 1;

	for (i = 0; s[i]; i++)
	{
		if (new_word && s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
		new_word = 0;
		for (j = 0; sep[j]; j++)
		{
			if (s[i] == sep[j])
				new_word = 1;
		}
	}
	return (s);
}
