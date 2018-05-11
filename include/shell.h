/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** Contains the prototypes of the project's functions.
*/

#ifndef FOURTY_TWO_SHELL_H
#define FOURTY_TWO_SHELL_H

#include "const.h"
#include "struct.h"
#include "macro.h"
#include "error_general.h"
#include "command.h"
#include "builtins.h"

//env.c
char **env_dup(char **envp);
int get_pos_env(char **env, char *name);

//shell.c
void display_prompt(void);
void shell(shell_t *mysh);

#endif