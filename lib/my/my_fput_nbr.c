/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Puts the number given as a parameter in a file.
*/

#include <unistd.h>
#include "my.h"

static void my_fput_posnbr(int fd, unsigned int n)
{
	if (n > 9)
		my_fput_posnbr(fd, n / 10);
	my_fputc(fd, n % 10 + '0');
}

void my_fput_nbr(int fd, int n)
{
	if (n < 0) {
		write(fd, "-", 1);
		n = -n;
	}
	my_fput_posnbr(fd, n);
}