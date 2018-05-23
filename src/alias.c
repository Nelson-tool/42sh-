/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Alias tree functions.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my.h"
#include "shell.h"

alias_t *create_alias(const char *name, const char *value)
{
	alias_t *alias = malloc(sizeof(node_t));

	if (alias == NULL) {
		perror("malloc");
		return (NULL);
	}
	memset(alias, 0, sizeof(node_t));
	alias->name = strdup(name);
	if (alias->name == NULL) {
		perror("malloc in strdup");
		free(alias);
		return (NULL);
	}
	alias->value = strdup(value);
	if (alias->value == NULL) {
		perror("malloc in strdup");
		free(alias->name);
		free(alias);
		return (NULL);
	}
	return (alias);
}

void del_alias(alias_t *alias)
{
	if (alias->higher != NULL)
		del_alias(alias->higher);
	if (alias->lower != NULL)
		del_alias(alias->lower);
	free(alias->name);
	free(alias->value);
	free(alias);
}

void show_alias_tree(alias_t *tree)
{
	if (tree->lower != NULL)
		show_alias_tree(tree->lower);
	printf("%s\t%s\n", tree->name, tree->value);
	if (tree->higher != NULL)
		show_alias_tree(tree->higher);
}

char *search_alias(alias_t *tree, const char *name)
{
	int diff = strcmp(tree->name, name);

	if (diff > 0) {
		if (tree->lower == NULL)
			return (NULL);
		return (search_alias(tree->lower, name));
	} else if (diff < 0) {
		if (tree->higher == NULL)
			return (NULL);
		return (search_alias(tree->higher, name));
	} else
		return (tree->value);
}