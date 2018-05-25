/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Displays its arguments.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "shell.h"

static int check_param(char *arg, int *opt_l, int j)
{
	for (int i = 0 ; i < NB_ECHO_SEQS ; ++i) {
		if (arg[j] == '\\' && arg[j + 1] == ECHO_SEQS[i])
			opt_l[i]++;
	}
	return (0);
}

static void echo(char *arg, int *opt_l)
{
	char *result = NULL;
	int i = 0;

	for (i = 0 ; arg[i + 1] ; ++i)
		check_param(arg, opt_l, i);
	result = rewrite_arg(arg, opt_l);
	if (result == NULL)
		return;
	printf(result);
	free(result);
}

void builtin_echo(UNUSED shell_t *mysh, char **command)
{
	int opt_l[NB_ECHO_SEQS + 1];
	int i = 0;

	for (int i = 0 ; i < NB_ECHO_SEQS ; i++)
		opt_l[i] = 0;	
	memset(opt_l, 0, NB_ECHO_SEQS + 1);
	for (i = 1 ; command[i] != NULL ; i++) {
		echo(command[i], opt_l);
		if (command[i + 1] != NULL)
			printf(" ");
	}
	if (opt_l[2] != 1)
		printf("\n");
}
