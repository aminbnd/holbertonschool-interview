#include "substring.h"

/**
 * find_substring - function that finds all the possible substrings
 * containing a list of words, within a given string.
 *
 * @s: The string to be scanned
 * @words: is the array of words all substrings must
 * be a concatenation arrangement of
 * @nb_words:  is the number of elements
 * in the array words
 * @n: holds the address at which to store the number of
 * elements in the returned array.
 * Return: an allocated array, storing each index in s, at which a
 * substring was found.
 */

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int stringlen, wordlen, j, i, k;
	int *elements, *found;

	if (!s || !words || !n || nb_words == 0)
		return (NULL);

	*n = 0;
	stringlen = strlen(s);
	wordlen = strlen(words[0]);
	found = malloc(nb_words * sizeof(int));
	elements = malloc(stringlen * sizeof(int));
	for (i = 0; i <= stringlen - nb_words * wordlen; i++)
	{
		for (j = 0; j < nb_words; j++)
			found[j] = 0;
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < nb_words; k++)
			{
				if (found[k] == 0 && strncmp(s + i + j * wordlen, words[k], wordlen) == 0)
				{
					found[k] = 1;
					break;
				}
			}
			if (k == nb_words)
				break;
		}
		if (j == nb_words)
			elements[(*n)++] = i;
	}
	free(found);
	return (elements);
}
