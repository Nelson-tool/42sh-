/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** Searches for a string in a string.
*/

#include "my.h"

int my_strstr(const char *haystack, const char *needle)
{
	int len_haystack = my_strlen(haystack);
	int len_needle = my_strlen(needle);

	for (int i = 0 ; i + len_needle <= len_haystack ; ++i) {
		if (my_strncmp(haystack + i, needle, len_needle) == 0)
			return (i);
	}
	return (-1);
}