/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** Macros header file.
*/

#ifndef MACROS_H
#define MACROS_H

#ifndef __GNUC__
#	define __attribute__(x)
#endif

#define UNUSED __attribute__((unused))
#define ESCAPED(str, i) (i != 0 && str[i - 1] == '\\')

#endif