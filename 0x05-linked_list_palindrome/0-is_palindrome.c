#include "lists.h"
/**
 * is_palindrome -  Checks if a linked list is a palindrome
 * @head: Linked list to be checked
 * Return: 1 if list is palindrome 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *oldHead = *head;
	int counter = 0, i = 0;
	int list[2048];

	for (i = 0; oldHead; i++)
		oldHead = oldHead->next;
	if (i == 0)
		return (1);
	oldHead = *head;
	for (counter = 0; oldHead; oldHead = oldHead->next, counter++)
		list[counter] = oldHead->n;
	for (counter = 0; counter < i; counter++)
	{
		if (list[counter] != list[i - counter - 1])
			return (0);
	}
	return (1);
}