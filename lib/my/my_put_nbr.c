/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Displays the number given as a parameter.
*/

#include <unistd.h>
#include "my.h"

static void my_put_posnbr(unsigned int n)
{
	if (n > 9)
		my_put_posnbr(n / 10);
	my_putchar(n % 10 + '0');
}

void my_put_nbr(int n)
{
	if (n < 0) {
		write(STDOUT_FILENO, "-", 1);
		n = -n;
	}
	my_put_posnbr(n);
}