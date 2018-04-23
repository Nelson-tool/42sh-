/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** Searches for a character in a string.
*/

#include <stdlib.h>
#include <stdbool.h>
#include "my.h"

bool in_str(char const c, char const *str)
{
	for (int i = 0 ; str[i] ; ++i) {
		if (c == str[i])
			return (true);
	}
	return (false);
}

int my_rindex(const char c, const char *str)
{
	for (int i = my_strlen(str) ; i >= 0 ; --i) {
		if (c == str[i])
			return (i);
	}
	return (-1);
}