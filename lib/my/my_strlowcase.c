/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Puts every letter of every word in it in uppercase.
*/

#include <ctype.h>
#include "my.h"

char *my_strlowcase(char *str)
{
	for (int i = 0 ; str[i] ; ++i)
		str[i] = tolower(str[i]);
	return (str);
}