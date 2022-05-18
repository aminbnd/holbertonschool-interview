#include "stdio.h"

/**
 * regex_match - function that checks whether a given
 * pattern matches a given string.
 *
 * @str: is the string to scan
 * @pattern: is the regular expression
 * Return: 1 if the pattern matches the string, or 0 if it doesn’t
 */

int regex_match(char const *str, char const *pattern)
{
	int exp1 = 0, exp2 = 0;

	if (!str || !pattern)
		return (0);

	exp1 = *str && (*str == *pattern || *pattern == '.');
	exp2 = *(pattern + 1) == '*';

	if (!*str && !exp2)
		return (*pattern ? 0 : 1);

	if (exp1 && exp2)
		return (regex_match(str + 1, pattern) || regex_match(str, pattern + 2));

	else if (exp1 && !exp2)
		return (regex_match(str + 1, pattern + 1));
	else if (exp2)
		return (regex_match(str, pattern + 2));

	return (0);
}
