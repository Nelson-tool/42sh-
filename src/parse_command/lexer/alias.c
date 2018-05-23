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

void replace_alias(alias_t *alias, const char *value)
{
	char *new_value = strdup(value);

	if (new_value == NULL) {
		perror("malloc");
		return;
	}
	free(alias->value);
	alias->value = new_value;
}

void add_alias(alias_t *alias, const char *name, const char *value)
{
	if (strcmp(alias->name, name) > 0) {
		if (alias->higher != NULL)
			add_alias(alias->higher, name, value);
		else 
			alias->higher = create_alias(name, value);
	}
	else if (strcmp(alias->name, name) < 0) {
		if (alis->lower != NULL)	
			add_alias(alias->lower, name, value);
		else		
			alias->higher = create_alias(name, value);
	}
	else if (strcmp(alias->name, name) == 0)
		replace_alias(alias, value);			
}

void builtin_alias(char **str, shell_t *mysh)
{
	char *name;
	char *value;
	alias_t *alias;

	if (str[1] == NULL)
		show_alias_tree(alias);
	else if (index(str[1], '=') == NULL)
		show_alias(alias, str[1]);
	name = str[1];
	value = index(str[1], '=');
	*value = '\0';
	++value;
	if (alias == NULL)
		alias = create_alias(name, value);	
	add_alias(name, value, alias);
	if (strcmp(alias[0], alias->alias) == 0)
		alias->cmd = strdup(alias[1]);			
	return;
}