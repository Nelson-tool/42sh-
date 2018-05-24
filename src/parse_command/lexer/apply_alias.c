/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Applies aliases to the command tree.
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "my.h"
#include "shell.h"

char **alias_switch_expr(char **expr, const char *value)
{
	char **value_tab;
	int len_value_tab;
	int init_len;
	char **new_expr;
	int size = sizeof(char *);

	value_tab = rec_split_words(value, 0);
	init_len = my_strlen_tab((void *) expr);
	len_value_tab = my_strlen_tab((void *) value_tab);
	new_expr = malloc(size * (init_len + len_value_tab));
	memcpy(new_expr, value_tab, size * len_value_tab);
	memcpy(new_expr + len_value_tab, expr + 1, size * init_len);
	free(value_tab);
	free(expr[0]);
	free(expr);
	return (new_expr);
}

void apply_alias(node_t *tree, alias_t *alias)
{
	char *value;

	if (tree->left != NULL)
		apply_alias(tree->left, alias);
	if (tree->right != NULL)
		apply_alias(tree->right, alias);
	if (tree->op == EXPR && alias && tree->expr[0]) {
		value = find_alias(alias, tree->expr[0]);
		if (value != NULL)
			tree->expr = alias_switch_expr(tree->expr, value);
	}
}
