/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** command for help
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "shell.h"

void builtin_help(UNUSED shell_t *mysh, char **command)
{
	int i = 0;
	
	for (; i < NB_HELP && command[1] != NULL; i++) {
		if (strcmp(command[1], TAB_HELP[i]) == 0) {
			printf(TAB_MSG[i]);
			break;
		}
	}
	if (!command[1])
		printf(HELP);
}
