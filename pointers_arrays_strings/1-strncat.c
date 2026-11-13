#include "main.h"

/**
 * _strncat - Concatenates at most n bytes of src to dest
 * @dest: Destination string
 * @src: Source string
 * @n: Maximum number of bytes to use from src
 *
 * Return: Pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0;

	while (dest[i])
		i++;
	while (j < n && src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}
