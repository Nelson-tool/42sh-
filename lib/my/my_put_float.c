/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Displays the float number given as a parameter.
*/

#include <unistd.h>
#include "my.h"

void my_put_float(double float_nb)
{
	int integer_part = float_nb;
	int float_part = (float_nb - integer_part) * 10000000;

	my_put_nbr(integer_part);
	my_putchar('.');
	my_put_nbr(float_part);
}