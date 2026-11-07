#include <stdio.h>
#include "main.h"

/**
 * print_to_98 - Prints all natural numbers from n to 98
 * @n: The starting number
 */
void print_to_98(int n)
{
	int step = (n <= 98) ? 1 : -1;

	while (n != 98)
	{
		printf("%d, ", n);
		n += step;
	}
	printf("98\n");
}
