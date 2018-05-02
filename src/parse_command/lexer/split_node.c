/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Splits a node if it contains a token.
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "42sh.h"

static token_t get_op(char *str)
{
	for (int i = 0 ; TOKENS[i] ; ++i) {
		if (strncmp(str, TOKENS[i], strlen(TOKENS[i])) == 0)
			return (i);
	}
	return (EXPR);
}

static char *move_past_token(char **str, const char *token)
{
	int pos = my_strstr(*str, token);
	char *left_expr = *str;

	if (pos == -1)
		pos = strlen(*str);
	*str += pos;
	return (left_expr);
}

bool split_node(node_t *node, const char *token, const char * const *tokens)
{
	char *copy = node->str;

	if (!create_branchs(node))
		return (false);
	node->left->str = move_past_token(&copy, token);
	node->op = get_op(copy);
	copy[0] = '\0';
	copy += strlen(TOKENS[node->op]);
	node->right->str = copy;
	token = get_token(node->right->str, tokens);
	if (token != NULL)
		return (split_node(node->right, token, tokens));
	return (true);
}