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
/**
 * listlenght - calculate the lenght of a linked list
 *
 *@lists: to the lenght of a linked list
 *Return: The lenght of a list
 */
size_t listlenght(const list_t *lists)
{
	size_t lenght;

	lenght = 0;
	while (lists)
	{
		lists = lists->next;
		lenght++;
	}
	return (lenght);
}
