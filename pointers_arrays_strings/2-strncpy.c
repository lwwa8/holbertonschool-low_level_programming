#include "main.h"

/**
 * _strncpy - Copies at most n bytes of src to dest
 * @dest: Destination buffer
 * @src: Source string
 * @n: Number of bytes to copy
 *
 * Return: Pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i]; i++)
		dest[i] = src[i];
	for (; i < n; i++)
		dest[i] = '\0';
	return (dest);
}
