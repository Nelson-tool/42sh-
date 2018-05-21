/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** Initialization header.
*/

#ifndef INIT_H
#define INIT_H

/* PROTOTYPES */
//init.c
void init_shell(shell_t *shell, char **env);

/* CONSTANT */
static const char CONF_FILE[] = ".42shrc";

/* MACRO */
#define DEFAULT_PATH		\
((char *[]) {"setenv", "PATH", "/bin:/usr/bin:/usr/local/bin/usr/sbin", NULL})

#endif