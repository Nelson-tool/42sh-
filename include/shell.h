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
#include "init.h"
#include "command.h"
#include "builtins.h"

//env.c
char **env_dup(char **envp);
int get_pos_env(char **env, char *name);

//bg_process.c
bg_process_t *bg_process_add(bg_process_t **list, pid_t pid, char **command);
pid_t bg_process_pop_back(bg_process_t **list);
pid_t bg_process_pop(bg_process_t **list, int pos);
void bg_process_del_all(bg_process_t *list);

//shell.c
void display_prompt(void);
void shell(shell_t *mysh);

#endif