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
			opt_l[i] = 1;
	}
	return (0);
}

static char *rewrite_arg(char *arg)
{
	unsigned int len_arg = strlen(arg);
	char *result = malloc(sizeof(char) * (len_arg + 1));
	int j = 0;

	if (result == NULL) {
		perror("malloc");
		return (NULL);
	}
	memset(result, 0, len_arg + 1);
	for (unsigned int i = 0 ; i < len_arg ; ++i) {
		if (arg[i] == '\\' && index(ECHO_SEQS, arg[i + 1])) {
			if (arg[i + 1] == 'n') {
				result[j++] = '\n';
				++i;
			}
		} else
			result[j++] = arg[i];
	}
	result[j] = '\0';
	return (result);
}

static void echo(char *arg, int *opt_l)
{
	char *result = NULL;
	int i = 0;

	for (i = 0 ; arg[i + 1] ; ++i)
		check_param(arg, opt_l, i);
	result = rewrite_arg(arg);
	if (result == NULL)
		return;
	printf(result);
	free(result);
}

void builtin_echo(UNUSED shell_t *mysh, char **command)
{
	int opt_l[NB_ECHO_SEQS + 1];
	int i = 0;

	memset(opt_l, 0, NB_ECHO_SEQS + 1);
	for (i = 1 ; command[i] != NULL ; i++) {
		echo(command[i], opt_l);
		if (command[i + 1] != NULL)
			printf(" ");
	}
	if (opt_l[2] != 1)
		printf("\n");
}
