#include "shell.h"
/**
 * _remove_comment - remove comment from line
 *
 *@lines: line that user entered
 *Return: lines without comment
 */
char *remove_comment(const char *lines)
{
	int commt_pos;

	commt_pos = _get_comment_position(lines);
	return (_strslice(lines, 0, commt_pos));
}
