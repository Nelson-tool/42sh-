/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** .h for the alias gestion
*/

#ifndef ALIAS_H
#define ALIAS_H

/* TYPEDEFS */
typedef struct alias{
	char *name;
	char *value;
	struct alias *lower;
	struct alias *higher;
} alias_t;


/* FUNCTIONS */
//alias.c
alias_t *create_alias(const char *name, const char *value);
void del_alias(alias_t *alias);
void show_alias_tree(alias_t *tree);
char *search_alias(alias_t *tree, const char *name);


/* CONSTANTS */
static const char * const DEF_ALIASES_NAMES[] =
{
	"-",
	"..",
	"...",
	"....",
	".....",
	"......",
	"ll",
	"l",
	"vi",
	"gaa",
	NULL
};

static const char * const DEF_ALIASES_VAL[] =
{
	"-",
	"cd ..",
	"cd ../..",
	"cd ../../..",
	"cd ../../../..",
	"cd ../../../../..",
	"ls -l",
	"ls -lah",
	"vim",
	"git add --all",
	NULL
};


#endif