/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** builtin_echo_opts.c
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"

static void check_opt(char *arg, char *result, int *opt_l)
{
	int j = 0;

	for (unsigned int i = 0 ; i < strlen(arg) ; ++i) {
		if (arg[i + 1] == '\\' && arg[i + 2] == ECHO_SEQS[1]) {
			i += 2;
		}
		switch (arg[i + 1]) {
		case 'f': case 'v':
			result[j] = '\n';
			j++;
			i++;
			for (int g = 0 ; g < i - 1 ; g++) {
				result[j] = ' ';
				j++;
			}
			break;
		case 't':
			result[j] = '\t';
			j++;
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
