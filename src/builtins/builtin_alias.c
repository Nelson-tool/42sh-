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

static void replace_alias(alias_t *alias, const char *value)
{
	char *new_value = strdup(value);

	if (new_value == NULL) {
		perror("malloc");
		return;
	}
	free(alias->value);
	alias->value = new_value;
}

static void add_alias(alias_t *alias, const char *name, const char *value)
{
	int diff = strcmp(alias->name, name);

	if (diff > 0) {
		if (alias->lower != NULL)
			add_alias(alias->lower, name, value);
		else
			alias->lower = create_alias(name, value);
	} else if (diff < 0) {
		if (alias->higher != NULL)
			add_alias(alias->higher, name, value);
		else
			alias->higher = create_alias(name, value);
	} else
		replace_alias(alias, value);
}

void set_alias(shell_t *mysh, const char *name, const char *value)
{
	if (mysh->alias == NULL)
		mysh->alias = create_alias(name, value);
	else
		add_alias(mysh->alias, name, value);
}

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
			value = (mysh->alias) ? search_alias(mysh->alias, command[i]) : NULL;
			if (value != NULL)
				puts(value);
		}
	}
	mysh->exit_status = 0;
}