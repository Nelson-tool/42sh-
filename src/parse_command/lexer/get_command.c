/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Recuperates the command from the users' input.
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "my.h"
#include "42sh.h"

/*node_t *get_root_elem(node_t *list)
{
	node_t *cur;

	for (int i = 0 ; TOKENS_PRIOR[i] ; ++i) {
		cur = list;
		while (cur) {
			for (int j = 0 ; TOKENS_PRIOR[i][j] != EXPR ; ++j) {
				if (cur->op == TOKENS_PRIOR[i][j])
					return (cur);
			}
			cur = cur->right;
		}
	}
	return (list);
}

token_t get_token(node_t *node, const token_t *tokens)
{
	for (int i = 0 ; tokens[i] != EXPR ; ++i) {
		if (node->op == tokens[i])
			return (tokens[i]);
	}
	return (-1);
}

void set_node_in_tree(node_t *root, const token_t *tokens, node_t *came_from)
{
	token_t token = get_token(root, tokens);

	if (token != -1) {
		root->left->right = NULL;
		if (root->left->left != NULL)
			root->left = root->left->left;
		root->right->left = NULL;
		if (root->right->right != NULL)
			root->right = root->right->right;
	}
	if (root->left != NULL && root->left != came_from)
		set_node_in_tree(root->left, tokens, root);
	if (root->right != NULL && root->left != came_from)
		set_node_in_tree(root->right, tokens, root);
}

void transform_into_tree(node_t **root)
{
	*root = get_root_elem(*root);
	for (int i = 0 ; TOKENS_PRIOR[i] ; ++i)
		set_node_in_tree(*root, TOKENS_PRIOR[i], NULL);
}*/

static void cut_comment(char *str)
{
	char *com = index(str, '#');

	if (com != NULL)
		*com = '\0';
}

node_t *parse_line(char *line)
{
	node_t *tree = NULL;

	cut_comment(line);
	if (!check_quotes(line))
		return (NULL);
	/*tree = list_command(line);
	if (tree == NULL)
		return (NULL);
	transform_into_tree(&tree);
	if (!split_expressions(tree) || !check_syntax(tree)) {
		del_tree(tree);
		return (NULL);
	}*/
	tree = ll_lexer(line);
	//show_tree(tree);
	return (tree);
}

node_t *get_command(shell_t *mysh)
{
	char *line = get_next_line(STDIN_FILENO);
	node_t *tree = NULL;

	if (line == NULL) {
		mysh->stop = true;
		if (mysh->tty)
			my_putstr("exit\n");
		return (NULL);
	}
	tree = parse_line(line);
	free(line);
	if (tree == NULL) {
		mysh->exit_status = 1;
		return (NULL);
	}
	return (tree);
}
