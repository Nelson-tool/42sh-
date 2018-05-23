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
		if (alias->higher != NULL)
			add_alias(alias->higher, name, value);
		else
			alias->higher = create_alias(name, value);
	} else if (diff < 0) {
		if (alias->lower != NULL)
			add_alias(alias->lower, name, value);
		else
			alias->higher = create_alias(name, value);
	} else
		replace_alias(alias, value);
}

static void set_alias(shell_t *mysh, char **command, char *name, char *value)
{
	*value = '\0';
	++value;
	if (mysh->alias == NULL)
		mysh->alias = create_alias(name, value);
	else
		add_alias(mysh->alias, name, value);
	if (command[2] != NULL)
		mysh->exit_status = 1;
	else
		mysh->exit_status = 0;
}

void builtin_alias(shell_t *mysh, char **command)
{
	char *value;
	int invalid = 0;

	if (command[1] == NULL)
		show_alias_tree(mysh->alias);
	for (int i = 1 ; command[i] ; ++i) {
		value = index(command[i], '=');
		if (value != NULL)
			set_alias(mysh, command, command[1], value);
		else {
			value = search_alias(mysh->alias, command[i]);
			if (value != NULL)
				puts(value);
			else
				++invalid;
		}
	}
	if (!invalid)
		mysh->exit_status = 0;
	else
		mysh->exit_status = 1;
}