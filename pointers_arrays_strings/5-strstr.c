#include "main.h"

/**
 * _strstr - Locates a substring
 * @haystack: The string to search
 * @needle: The substring to find
 *
 * Return: Pointer to the beginning of the substring, or NULL
 */
char *_strstr(char *haystack, char *needle)
{
	int i;

	if (*needle == '\0')
		return (haystack);
	while (*haystack)
	{
		for (i = 0; needle[i] && haystack[i] == needle[i]; i++)
			;
		if (needle[i] == '\0')
			return (haystack);
		haystack++;
	}
	return ((char *)0);
}
