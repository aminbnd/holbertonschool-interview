#include "lists.h"
/**
 * insert_node - inserts a node in a linked list
 * @head: head of the list
 * @number: the number to be inserted
 * Return: adress of the new node, or NULL if failed
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *tmp;
	tmp = *head;
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	if (*head == NULL || (*head)->n >= new->n)
	{
		new->next = *head;
		*head =new;
		return (new);
	}

	while (tmp != NULL)
	{
		if (tmp->next == NULL || tmp->next->n > new->n)
		{
			new->next = tmp->next;
			tmp->next = new;
			break;
		}
		tmp = tmp->next;
	}
	return (new);
	
}