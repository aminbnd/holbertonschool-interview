#include "lists.h"
/**
 * is_palindrome -  Checks if a linked list is a palindrome
 * @head: Linked list to be checked
 * Return: 1 if list is palindrome 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *prevHead = *head;
	int j;
	int i;
	int list[1024];

	for (i = 0; prevHead; i++)
		prevHead = prevHead->next;
	if (i == 0)
		return (1);
	prevHead = *head;

	for (j = 0; prevHead; prevHead = prevHead->next, j++)
		list[j] = prevHead->n;
	
	for (j = 0; j < i; j++)
	{
		if(list[j] != list[i - j - 1])
			return (0);
	}
	return (1);
}