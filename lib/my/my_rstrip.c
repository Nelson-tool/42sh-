/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** Strips the last occurences of a char in a string.
*/

#include <string.h>
#include "my.h"

void my_rstrip(char *str, const char *strip)
{
	int last = strlen(str) - 1;

	for (; last >= 0 && in_str(str[last], strip) ; --last)
		str[last] = '\0';
}