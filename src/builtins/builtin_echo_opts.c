/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Options of builtin echo.
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"

static int v_or_t(char *result, int j, int nbr, int i)
{
	if (nbr == 'v') {
		result[j] = '\n';
		j++;
		for (int g = 0 ; g < i ; g++) {
			result[j] = ' ';
			j++;
		}
	} else {
		result[j] = '\t';
		j++;
	}
	return (j);
}

static void check_opt(char *arg, char *result, int *opt_l)
{
	int j = 0;

	for (unsigned int i = 0 ; i < strlen(arg) ; ++i) {
		if (arg[i + 1] == '\\' && arg[i + 2] == ECHO_SEQS[1])
			i += 2;
		if (arg[i] == '\\') {
			switch (arg[i + 1]) {
			case 'f': case 'v': case 't':
				j = v_or_t(result, j, arg[i + 1], i);
				i++;
				break;
			case 'r':
				opt_l[6] = 0;
				i++;
				break;
			}
			if (arg[i] == '\\' && index(ECHO_SEQS, arg[i + 1])) {
				if (arg[i + 1] == 'n') {
					result[j++] = '\n';
					++i;
				}
			}
		} else
			if (opt_l[6] != 1)
				result[j++] = arg[i];
	}
	result[j] = '\0';
}

char *rewrite_arg(char *arg, int *opt_l)
{
	unsigned int len_arg = strlen(arg);
	char *result;

	if (opt_l[4] != 0)
		result = malloc(sizeof(char) * ((len_arg + 1) * (opt_l[4] + 2)));
	else
		result = malloc(sizeof(char) * (len_arg + 1));

	if (result == NULL) {
		perror("malloc");
		return (NULL);
	}
	memset(result, 0, len_arg + 1);
	check_opt(arg, result, opt_l);
	return (result);
}
