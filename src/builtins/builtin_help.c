/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Displays help about builtins.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "shell.h"

void builtin_help(UNUSED shell_t *mysh, char **command)
{
	int i = 0;

	if (command[1] == NULL) {
		printf(HELP);
		return;
	}
	for (int i = 0 ; i < NB_HELP ; i++) {
		if (strcmp(command[1], TAB_HELP[i]) == 0) {
			printf(TAB_MSG[i]);
			break;
		}
	}
}
