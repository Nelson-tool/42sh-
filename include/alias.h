/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** .h for the alias gestion
*/

#ifndef ALIAS_H
#define ALIAS_H

typedef struct Alias alias;
struct alias{
	char *alias;
	char *cmd;
	int *previous;
	int *higher;
	int *lower;
};

typedef struct Aliste aliste;
struct aliste {
	alias *alias;	
};

#endif ALIAS_H