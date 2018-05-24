/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Alias management.
*/

#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "shell.h"

void builtin_alias(shell_t *mysh, char **command)
{
	char *value;

	if (command[1] == NULL) {
		if (mysh->alias)
			show_alias_tree(mysh->alias);
	}
	for (int i = 1 ; command[i] ; ++i) {
		value = index(command[i], '=');
		if (value != NULL) {
			*value = '\0';
			++value;
			set_alias(mysh, command[i], value);
		} else {
			value = (mysh->alias) ? find_alias(mysh->alias, command[i]) : NULL;
			if (value != NULL)
				puts(value);
		}
	}
	mysh->exit_status = 0;
}