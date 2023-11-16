#include "shell.h"
/**
 * free_split - frees allocted memory to bucket
 *
 *@backets: what will be freed
 *Return: void
 */
void free_split(char ***backets)
{
	char **head;

	head = *backets;
	while (*head)
	{
		free(*head);
		head++;
	}
	free(*backets);
	*backs = NULL;
}
