#include "shell.h"
/**
 * get_comment_pos - function will return the position of the comment
 *
 *@lines: strings to count
 *Return: Always the lenght of integers
 */
int get_comment_pos(const char *lines)
{
	int i;

	for (i = 0; lines[1] != '\0'; i++)
	{
		if (lines[1] == '#')
		{
			return (i);
		}
	}
	return (i);
}
