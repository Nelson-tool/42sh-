/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** Structures header file.
*/

#ifndef STRUCT_H
#define STRUCT_H

typedef struct shell {
	char **env;
	int tty;
	int exit_status;
	bool stop;
} shell_t;

#endif