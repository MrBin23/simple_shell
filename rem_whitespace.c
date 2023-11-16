#include "shell.h"
/**
 * _rem_whitespace - function returns newline
 *
 *@lines: lines that will be checked
 *Return: Newline with no duplicate space
 */
char *_rem_whitespace(const char *lines)
{
	size_t l;
	size_t r;
	char *s;

	l = 0;
	r = _stringlenght(lines);
	if (!r)
	{
		s = malloc(sizeof(char));
		*s = 0;
		return (s);
	}
	r -= 1;
	while (lines[l] == ' ' || lines[l] == '\t')
		l++;
	while (r > l && (lines[r] == ' ' || lines[r] == '\t'))
		r--;
	if (l > r)
	{
		s = malloc(sizeof(char));
		*s = 0;
		return (s);
	}
	return (_get_newline_withnospace(lines + l, r - l));
}
/**
 * _get_lenght_withnospace - returns lenght of strings with no space
 *
 * @lines: lines to return with no space
 * @ends: The end of line retured
 * Return: The lenght
 */
size_t _get_lenght_withnospace(const char *lines, size_t ends)
{
	size_t beggin;
	size_t lenght;
	int space;

	beggin = 0;
	space = 0;
	lenght = 0;
	while (beggin < ends)
	{
		if ((lines[beggin] == ' ' || lines[beggin] == '\t') && !space)
		{
			lenght++;
			space = 1;
		}
		else if (lines[beggin] != ' ' && lines[beggin] != '\t')
		{
			space = 0;
			lenght++;
		}
		beggin++;
	}
	return (lenght);
}
/**
 * _get_newline_withnospace - fnction returns newline
 *
 *@lines: Lines to checks for
 *@ends: ends of line checked for
 *Return: ALways the new string line
 */
size_t *_get_newline_withnospace(const char *lines, size_t ends)
{
	size_t beggin;
	size_t indx;
	int space;
	char *newlines;

	beggin = 0;
	space = 0;
	indx = 0;
	newlines = malloc(sizeof(char) *
			(_get_lenght_withnospace(lines, ends + 1) + 1));
	if (!newlines)
		return (NULL);
	while (beggin <= ends)
	{
		if ((lines[beggin] == ' ' || lines[beggin] == '\t') &&
				!space)
		{
			newlines[indx] = ' ';
			indx++;
			space = 1;
		}
		else if (lines[beggin] != ' ' && lines[beggin] != '\t')
		{
			space = 0;
			newlines[indx] = lines[beggin];
			indx++;
		}
		beggin++;
	}
	newlines[indx] = 0;
	return (newlines);
}
