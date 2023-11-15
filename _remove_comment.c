#include "shell.h"
/**
 * remove_comment - remove comment from line
 *
 *@lines: line that user entered
 *Return: lines without comment
 */
char *remove_comment(const char *lines)
{
	int commt_pos;

	commt_pos = get_comment_pos(lines);
	return (str_slice(lines, 0, commt_pos));
}
