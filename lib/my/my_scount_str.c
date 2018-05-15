/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** Counts the number of occurence of a string in a string.
*/

#include <string.h>
#include "my.h"

int my_scount_str(const char *search, const char *str)
{
	int len_srch = strlen(search);
	int len = strlen(str);
	int count = 0;

	for (int i = 0 ; i < len - len_srch ; ++i) {
		if (strncmp(search, str + i, len_srch) == 0)
			++count;
	}
	return (count);
}