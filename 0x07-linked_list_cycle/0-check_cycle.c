#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: head of the list
 * Return: 1 if linked list is cycled 0 otherwise
 */

int check_cycle(listint_t *list)
{
	listint_t *hare, *turtle;

	if (list == NULL || list->next == NULL)
		return (0);
	turtle = list;
	hare = list->next->next;

	while (turtle != hare)
	{
		if (hare == NULL || hare->next == NULL)
			return (0);
		hare = hare->next->next;
		turtle = turtle->next;
	}

	return (1);
}
