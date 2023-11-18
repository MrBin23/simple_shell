#include "shell.h"
/**
 * check_diam - function finds next dimeter
 *
 *@string: strings to check
 *@diam: diameter used for splitting
 *Return: 0 if the string does not have diameter
 */
int check_diam(const char *string, const char *diam)
{
	size_t iterates;

	iterates = 0;
	while (string[iterates] && diam[iterates] &&
			string[iterates] == diam[iterates])
	{
		iterates++;
	}
	if (diam[iterates])
	{
		return (0);
	}
	if (string[iterates] == diam[iterates - 1])
	{
		return (2);
	}
	return (1);
}
/**
 * free_backs - function will free the backs
 *
 *@backs: array that will be freed
 *@curr_pos: last index before error
 *Return: nothing
 */
void free_backs(char **backs, size_t curr_pos)
{
	size_t indx;

	indx = 0;
	while (indx < curr_pos)
	{
		free(backs[indx]);
		indx++;
	}
	free(backs);
}
/**
 * backs_counter - function calculate nuber of packs splitted
 *
 *@lines: Buffer to check
 *@diam: buffer that will be checked for
 *Return: Th e number of backets
 */
size_t backs_counter(const char *lines, const char *diam)
{
	size_t count, indx;
	size_t before, is_diam;

	count = 0;
	indx = 0;
	before = 0;
	if (!*lines)
		return (0);
	while (lines[indx])
	{
		is_diam = check_diam(lines + indx, diam);
		if (is_diam)
		{
			if (is_diam == 2)
			{
				indx++;
				before = 1;
			}
			else if (is_diam == 1 && before)
			{
				before = 0;
				indx++;
			}
			else
			{
				count++;
				indx += _stringlenght(diam);
			}
		}
		else
		indx++;
	}
	return (count + 1);
}
/**
 * find_next_diam - function returns the start of next diam
 *
 *@lines: buffer to check
 *@diam: buffer to check
 *Return: next occurence of diam
 */
size_t find_next_diam(const char *lines, const char *diam)
{
	size_t before;
	size_t is_diam;
	size_t indx;

	indx = 0;
	before = 0;
	while (lines[indx])
	{
		is_diam = check_diam(lines + indx, diam);
		if (is_diam)
		{
			if (is_diam == 2)
			{
				indx++;
				before = 1;
			}
			else if (is_diam == 1 && before)
			{
				before = 0;
				indx++;
			}
			else
				return (indx);
		}
		else
			indx++;
	}
	return (indx);
}
/**
 * _splits - splitting lines of diameter
 *
 *@lines: buffer line to be splitted
 *@diam: diameter that will be split in
 *Return: arrays that ends with NYULL
 */
char **_splits(const char *lines, const char *diam)
{
	char **backets;
	size_t backs_len, curr_line_pos;
	size_t backs_indx, next_diam;

	backs_len = backs_counter(lines, diam);
	backets = malloc(sizeof(char *) * (backs_len) + 1);
	if (!backets)
		return (NULL);
	curr_line_pos = 0;
	backs_indx = 0;
	while (backs_indx < backs_len)
	{
		next_diam = find_next_diam(lines + curr_line_pos, diam);
		backets[backs_indx] = malloc(sizeof(char) * (next_diam + 1));
		if (!backets[backs_indx])
		{
			free_backs(backets, backs_indx);
			return (NULL);
		}
		_copies(backets[backs_indx], lines + curr_line_pos, next_diam);
		backs_indx++;
		curr_line_pos += next_diam + _stringlenght(diam);
	}
	backets[backs_len] = NULL;
	return (backets);
}
