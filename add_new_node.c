#include "shell.h"
#include <stdlib.h>
/**
 * add_to_list - addig new node to the linked list
 *@lists: double pointer to the head of the list
 *@data: Ponter to the items that will be stored
 *Return: Pointer to the newly added node
 */
list_t *add_new_node(list_t **lists, void *data)
{
	list_t *newnode = (list_t *)malloc(sizeof(list_t));
	list_t *curr_node;

	if (new_node == NULL)
	{
		return (NULL);
	}
	newnode->data = data;
	newnode->next = NULL;

	if(*lists == NULL)
	{
		*lists = newnode;
	}
	else
	{
		curr_node = *lists;
		while (curr_node->next != NULL)
		{
			curr_node = curr_node->next;
		}
		curr_node->next = new_node;
	}
	return (newnode);
}
