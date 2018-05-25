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
	int len_cat;
	int old_len;
	int new_len;
	char *new_str;

	if (str == NULL)
		return (strdup(cat));
	if (cat != NULL) {
		old_len = strlen(str);
		len_cat = strlen(cat);
		new_len = old_len + len_cat + 1;
		new_str = realloc(str, new_len);
		if (new_str == NULL) {
			perror("realloc");
			return (str);
		}
		str = new_str;
		strcpy(str + old_len, cat);
	}
	return (str);
}