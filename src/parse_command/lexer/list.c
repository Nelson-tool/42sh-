/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Handles the list created by list_command().
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "42sh.h"

static void add_elem_list(node_t **first, node_t *new)
{
	node_t *cur;

	if (*first == NULL) {
		*first = new;
		new->left = NULL;
	} else {
		cur = *first;
		while (cur->right)
			cur = cur->right;
		cur->right = new;
		new->left = cur;
	}
}

bool add_expr_list(node_t **first, char *line, int size)
{
	node_t *new = malloc(sizeof(node_t));

	if (new == NULL) {
		perror("malloc");
		return (false);
	}
	new->str = malloc(sizeof(char) * (size + 1));
	if (new->str == NULL) {
		perror("malloc");
		free(new);
		return (false);
	}
	strncpy(new->str, line, size);
	new->str[size] = '\0';
	new->op = EXPR;
	new->right = NULL;
	add_elem_list(first, new);
	return (true);
}

bool add_token_list(node_t **first, token_t token)
{
	node_t *new = malloc(sizeof(node_t));

	if (new == NULL) {
		perror("malloc");
		return (false);
	}
	new->str = NULL;
	new->op = token;
	new->right = NULL;
	add_elem_list(first, new);
	return (new);
}

void cleanup_list(node_t *list)
{
	node_t *to_del;

	while (list) {
		to_del = list;
		list = list->right;
		if (to_del->op == EXPR)
			free(to_del->str);
		free(to_del);
	}
}
