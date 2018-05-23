/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** .h for the alias gestion
*/

#ifndef ALIAS_H
#define ALIAS_H

typedef struct alias{
	char *name;
	char *value;
	struct alias *lower;
	struct alias *higher;
} alias_t;

//alias.c
void show_alias_tree(alias_t *tree);

#endif