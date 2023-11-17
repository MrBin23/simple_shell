#include "shell.h"
/**
 * _isdigit - function checks for digit
 *
 *@str: pointer to string to convert
 * Return: 1 as digit, else return 0
 */
int _isdigit(const char *str)
{
	if (!str)
	{
		return (0);
	}
	if (*str == '-' || *str == '+')
	{
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
		return (0);
		str++;
	}
	return (1);
}

