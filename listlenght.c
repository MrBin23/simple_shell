#include "shell.h"
/**
 * listlenght - function calculate lenght of linked list
 *
 *@lists: to calculates leghnt of lists
 *Return: Always the legnth
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
