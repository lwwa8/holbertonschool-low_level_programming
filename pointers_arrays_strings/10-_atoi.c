#include "main.h"

/**
 * _atoi - Converts a string to an integer
 * @s: The string to convert
 *
 * Return: The converted integer, or 0 if there are no numbers
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, started = 0;
	unsigned int num = 0;

	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			num = num * 10 + (s[i] - '0');
		}
		else if (started)
			break;
		else if (s[i] == '-')
			sign = -sign;
		i++;
	}
	if (sign < 0)
		return ((int)(-num));
	return ((int)num);
}
