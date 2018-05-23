/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Unsets an alias.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "shell.h"

/*void unalias(alias_t *tree, char **to_unalias)
{
	int invalid = 0;

	for (int i = 0 ; to_unalias[i] ; ++i) {
		if (!del_alias(tree, to_unalias[i]))
			++invalid;
	}
	if (!invalid)
		mysh->exit_status = 0;
	else
		mysh->exit_status = 1;
}*/

void builtin_unalias(UNUSED shell_t *mysh, UNUSED char **command)
{
	/*if (command[1] == NULL) {
		puts("unalias: Too few arguments.");
		mysh->exit_status = 1;
		return;
	} else if (strcmp(command[1], "-a") == 0) {
		del_aliases(mysh->alias);
		mysh->exit_status = 0;
	} else
		unalias(mysh->alias, command + sizeof(char *));*/
}