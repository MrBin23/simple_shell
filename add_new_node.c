#include "shell.h"
#include <stdlib.h>
/**
 * add_new_node - addig new node to the linked list
 *@lists: double pointer to the head of the list
 *@datas: Ponter to the items that will be stored
 *Return: Pointer to the newly added node
 */
list_t *add_new_node(list_t **lists, void *datas)
{
	list_t *newnode = (list_t *)malloc(sizeof(list_t));
	list_t *curr_node;

	if (newnode == NULL)
	{
		return (NULL);
	}
	newnode->datas = datas;
	newnode->next = NULL;

	if (*lists == NULL)
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
		curr_node->next = newnode;
	}
	return (newnode);
}
