/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Adds a string or character at the end of a string.
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"

char *my_append(char *str, char const *cat)
{
	int len_cat = 0;
	int new_len = 0;

	if (str == NULL)
		return (strdup(cat));
	if (cat != NULL) {
		len_cat = strlen(cat);
		new_len = strlen(str) + len_cat + 1;
		str = realloc(str, new_len);
		if (str != NULL)
			str = strcat(str, cat);
	}
	return (str);
}