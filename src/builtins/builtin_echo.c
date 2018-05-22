/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** builtin echo
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "shell.h"

static int check_param(char *arg, int opt[12], int *opt_l, int j)
{
	for (int i = 0 ; i < 8; i++) {
		if (arg[j] == '\\' && arg[j + 1] == opt[i])
			opt_l[i] = 1;
	}
	return (0);
}

static char *rewrite_arg(char *arg)
{
	char *result = malloc(sizeof(char) * strlen(arg) + 1);
	unsigned int i = 0;
	int j = 0;

if (result == NULL) {
perror("malloc");
return (NULL);
}
	memset(result, 0, strlen(arg) + 1);
	for (; i < strlen(arg) ; i++) {
if (arg[i] == '\\' && index("abcfnrtv", arg[i + 1])) {
			if (arg[i + 1] == 'n') {
result[j] = '\n';
				i++;
				j++;
			}
		} else {
			result[j] = arg[i];
			j++;
		}
	}
	result[j] = '\0';
	return (result);
}

static void echo(char **command, int turn, int *opt, int *opt_l)
{
	char *result = NULL;
	int i = 0;

	if (command[turn] != NULL) {
		for (i = 0 ; command[turn][i + 1] ; i++)
			check_param(command[turn], opt, opt_l, i);
		result = rewrite_arg(command[turn]);
printf(result);
	}
}

void builtin_echo(UNUSED shell_t *mysh, char **command)
{
	int opt[12] = {'a', 'b', 'c', 'f', 'n', 'r', 't', 'v'};
	int opt_l[12];
	int i = 0;

	for (; i < 12 ; i++)
		opt_l[i] = 0;
	for (i = 1 ; command[i] != NULL ; i++) {
		echo(command, i, opt, opt_l);
		if (command[i + 1] != NULL)
			printf(" ");
	}
	if (opt_l[2] != 1)
		printf("\n");
}
