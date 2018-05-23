/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Alias tree functions.
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "shell.h"

node_t *create_alias(const char *name, const char *value)
{
	alias_t *alias = malloc(sizeof(node_t));

	if (alias == NULL) {
		perror("malloc");
		return (NULL);
	}
	memset(alias, 0, sizeof(node_t));
	alias->name = strdup(alias);
	if (alias->name == NULL) {
		perror("strdup");
		free(alias);
		return (NULL);
	}
	alias->value = strdup(value);
	if (alias->value == NULL) {
		perror("strdup");
		free(alias->name);
		free(alias);
		return (NULL);
	}
	return (alias);
}

bool create_abranchs(alias_t *alias)
{
	alias->higher = create_node();
	if (alias->higher == NULL)
		return (false);
	alias->lower = create_node();
	if (alias->lower == NULL) {
		free(alias->lower);
		alias->lower = NULL;
		return (false);
	}
	return (true);
}

void del_aliases(alias_t *alias)
{
	if (alias->higher != NULL)
		del_tree(alias->higher);
	if (alias->lower != NULL)
		del_tree(alias->lower);
	free(alias->name);
	free(alias->value);
	free(alias);
}

void show_alias_tree(alias_t *tree)
{
	if (tree->lower != NULL)
		show_alias_tree(tree->lower);
	if (tree->higher != NULL)
		show_alias_tree(tree->higher);
	printf("%s=%s\n", tree->name, tree->value);
}

char *search_alias(alias_t *tree, const char *name)
{
	int diff = strcmp(tree->name, name);

	if (diff < 0) {
		if (tree->lower == NULL)
			return (NULL);
		return (search_alias(tree->lower));
	} else if (diff > 0) {
		if (tree->higher == NULL)
			return (NULL);
		return (search_alias(tree->higher));
	} else
		return (tree->value);
}