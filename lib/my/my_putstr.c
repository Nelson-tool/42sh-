/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Displays, one-by-one, the characters of a string
*/

#include <unistd.h>
#include <string.h>
#include "my.h"

void my_putstr(char const *str)
{
	write(STDOUT_FILENO, str, strlen(str));
}