#include "shell.h"
/**
 * get_comment_pos - function will return the position of the comment
 *
 *@lines: strings to count
 *Return: Always the lenght of integers
 */
int get_comment_pos(const char *lines)
{
	int indx;

	for (indx = 0; lines[indx] != '\0'; indx++)
	{
		if (lines[indx] == '#')
		{
			return (indx);
		}
	}
	return (indx);
}
