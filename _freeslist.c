#include "shell.h"
/**
 * _freelist - free memory allocated for list
 *
 *@lists: pointer to head list
 *@free_content: ponter to function usedto free node
 *Return: void
 */
void _freelist(list_t *lists, void (*free_content)(void *data))
{
	list_t *curr = lists;
	list_t *next;

	while (curr != NULL)
	{
		next = curr->next;
		if (free_content != NULL)
		{
			free_content(curr->data);
		}
		free(curr);
		curr = next;
	}
}
