#include "shell.h"
/**
 * a_toi - converts a string representation of a num to an integer
 * @str: pointer to a null terminated string
 * Return: int value
 */
int a_toi(const char *str)
{
	int num, sign;

	num = 0;
	sign = 1;

	if (*str == '-')/*checks if first character of a string is minus*/
	{
		sign = -1;
		str++;
	}
	if (*str == '+')
	{
		str++;
	}

	while (*str)
	{
		num = num * 10 + (*str - 48);
		str++;
	}

	return (num * sign);
}
