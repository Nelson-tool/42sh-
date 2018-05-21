/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Splits the strings at the extremities of the tree into arrays of strings.
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "my.h"
#include "shell.h"

static int get_len_word(const char *str)
{
	int len = 0;
	char quote;

	while (str[len] && (!in_str(str[len], SEPS) || ESCAPED(str, len))) {
		if (in_str(str[len], QUOTES)) {
			quote = str[len];
			do {
				++len;
			} while (str[len] != quote || ESCAPED(str, len));
		}
		++len;
	}
	return (len);
}

static char *dup_arg(const char *str, int len)
{
	char *arg = malloc(sizeof(char) * (len + 1));
	char quote;
	int real_len = 0;

	if (arg == NULL) {
		perror("malloc");
		return (NULL);
	}
	for (int i = 0 ; i < len ; ++i) {
		if (str[i] == '\\' && in_str(str[i + 1], SEPS)) {
			arg[real_len++] = str[++i];
		} else if (in_str(str[i], QUOTES) && !ESCAPED(str, i)) {
			quote = str[i];
			++i;
			while (str[i] != quote) {
				if (str[i] == '\\' && str[i + 1] == quote) {
					arg[real_len++] = str[++i];
					++i;
				} else
					arg[real_len++] = str[i++];
			}
		} else if ((!in_str(str[i], SEPS)) || ESCAPED(str, i))
			arg[real_len++] = str[i];
	}
	arg[real_len] = '\0';
	return (arg);
}

static char **add_word(char **arr, const char *str, int len, int prof)
{
	arr[prof] = dup_arg(str, len);
	if (arr[prof] == NULL) {
		perror("malloc");
		for (int i = len ; arr[len] ; ++i)
			free(arr[i]);
		free(arr);
		return (NULL);
	}
	return (arr);
}

static char **rec_split_words(const char *str, int prof)
{
	int len;
	char **arr = NULL;

	while (in_str(str[0], SEPS))
		++str;
	if (str[0] == '\0') {
		arr = malloc(sizeof(char *) * (prof + 1));
		if (arr == NULL)
			perror("malloc");
		else
			arr[prof] = NULL;
	} else {
		len = get_len_word(str);
		arr = rec_split_words(str + len, prof + 1);
		if (arr == NULL)
			return (NULL);
		arr = add_word(arr, str, len, prof);
	}
	return (arr);
}

bool split_expressions(node_t *node)
{
	if (node->left != NULL && !split_expressions(node->left))
			return (false);
	if (node->right != NULL && !split_expressions(node->right))
			return (false);
	if (node->op == EXPR) {
		node->expr = rec_split_words(node->str, 0);
		if (node->expr == NULL) {
			perror("malloc");
			return (false);
		}
	}
	return (true);
}