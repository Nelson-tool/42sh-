/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Displays the content of an array of words.
*/

#include "my.h"

int my_show_word_array(char * const *arr)
{
	for (int i = 0 ; arr[i] ; ++i)
		puts(arr[i]);
	return (0);
}