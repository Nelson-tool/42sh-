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

node_t *create_alias(void)
{
	alias_t *alias = malloc(sizeof(node_t));

	if (alias == NULL) {
		perror("malloc");
		return (NULL);
	}
	memset(new_node, 0, sizeof(node_t));
	new_node->op = EXPR;
	return (new_node);
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

void del_tree(alias_t *alias)
{
	if (alias->higher != NULL)
		del_tree(alias->higher);
	if (alias->lower != NULL)
		del_tree(alias->lower);
	free(alias);
}

void show_tree(node_t *tree)
{
	if (tree == NULL)
		return;
	if (tree->op != EXPR) {
		printf("op: %s\n", TOKENS[tree->op]);
	} else {
		printf("expr: ");
		for (int i = 0 ; tree->expr[i] ; ++i) {
			printf("%s ", tree->expr[i]);
		}
		putchar('\n');
	}
	if (tree->left != NULL) {
		printf("left\n");
		show_tree(tree->left);
	}
	if (tree->right != NULL) {
		printf("right\n");
		show_tree(tree->right);
	}
}
