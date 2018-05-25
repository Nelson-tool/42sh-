/*
** EPITECH PROJECT, 2018
** help
** File description:
** help for help
*/

#ifndef HELP_H
#define HELP_H

static const char HELP_S_ECHO[] = " echo: echo [-neE] [arg ...]";
static const char HELP_S_HELP[] = " help: help [-dms] [pattern ...]";

static const char HELP_ECHO[] =
	"echo: echo [-neE] [arg ...]\n"
	"\tWrite arguments to the standard output.\n"
	"\tDisplay the ARGs, separated by a single space character and followed by a "
	"\tnewline, on the standard output.\n\tOptions:\n"
	"\t-n    do not append a newline\n\t-e    "
	"enable interpretation of the following backslash escapes\n\t-E    "
	"explicitly suppress interpretation of backslash escapes \n "
	"<< echo >> interprets the following backslash-escaped characters:\n\t\\a    "
	"alert (bell)\n\t\\b    backspace\n\t\\c    suppress further output\n\t\\e    "
	"escape character\n\t\\E    escape character\n\t\\f    form feed\n\t\\n"
	"new line\n\t\\r    carriage return\n\t\\t    horizontal tab\n\t\\v"
	"    vertical tab\n\t\\    backslash\n\t\\0nnn    the character "
	"whose ASCII code is NNN (octal).  NNN can be\n\t\t0 to 3 "
	"octal digits\n\t\\xHH    the eight-bit character whose value is HH (hexadecimal)."
	"HH\n\t\tcan be one or two hex digits\n\t\n\tExit Status:\n\tReturns"
	"success unless a write error occurs.\n";

static const char HELP_HELP[] =
	"help: help [-dms] [pattern ...]\n"
	"\tDisplay information about builtin commands.\n"
	"\tDisplays brief summaries of builtin commands. If PATTERN is \n"
	"\tspecified,gives detailed help on all commands matching PATTERN,\n"
	"\totherwise the list of help topics is printed.\n\tOptions:\n"
	"\t -d    output short description for each topic\n"
	"\t -m    display usage in pseudo-manpage format\n"
	"\t -s    output only a short usage synopsis for each topic matchingPATTERN\n"
	"\tArguments:\n"
	"\tPATTERN    Pattern specifiying a help topic \n\n"
	"\tExit Status: \n"
	"\tReturns success unless PATTERN is not found or an invalid option is given.\n";

static const char HELP_ALIAS[] =
	"alias: alias [-p] [name[=value] ... ]\n"
	"\tDefine or display aliases.\n"
	"\tWithout arguments, `alias' prints the list of aliases in the reusable\n"
	"\tform `alias NAME=VALUE' on standard output.\n"
	"\tOtherwise, an alias is defined for each NAME whose VALUE is given.\n"
	"\tA trailing space in VALUE causes the next word to be checked for\n"
	"\talias substitution when the alias is expanded.\n"
	"\tOptions:\n"
	"\t-p	print all defined aliases in a reusable format\n"
	"\tExit Status:\n"
	"\t alias returns true unless a NAME is supplied for which no alias has been\n"
	"\tdefined.\n";

static const char HELP_UNALIAS[] =
	"unalias: unalias [-a] name [name ...]\n"
	"\tRemove each NAME from the list of defined aliases.\n"
	"\tOptions:\n"
	"\t-a	remove all alias definitions\n"
	"\tReturn success unless a NAME is not an existing alias.\n";

static const char HELP_TRUE[] =
	"help true\n"
	"\ttrue: true\n"
	"\tReturn a successful result.\n"
	"\tExit Status:\n"
	"\tAlways succeeds.\n";

static const char HELP_FALSE[] =
	"false: false\n"
	"\tReturn an unsuccessful result.\n"
	"\tExit Status:\n"
	"\tAlways fails.\n";

static const char HELP_PWD[] =
	"pwd: pwd [-LP]\n"
	"\tPrint the name of the current working directory.\n"
	"\tOptions:\n"
	"\t-L	print the value of $PWD if it names the current working\n"
	"\tdirectory\n"
	"\t-P	print the physical directory, without any symbolic links\n"
	"\tBy default, `pwd' behaves as if `-L' were specified.\n"
	"\tExit Status:\n"
	"\tReturns 0 unless an invalid option is given or the current directory\n"
	"\tcannot be read.\n";

static const char HELP[] =
	"42sg, version 42.42.42(42)-release (x86_64-redhat-linux-42sh)\n"
	"These shell commands are defined internally.  Type `help' to see this list.\n"
	"Type `help name' to find out more about the function `name'.\n"
	"Use `man -k' to find out more about commands not in this list. \n"
	"\n"
	"A star (*) next to a name means that the command is disabled.\n"
	"\n"
	"job_spec [&]                                        history [-c] [-d offset] [n] or history -anrw [f>\n"
	"(( expression ))                                    if COMMANDS; then COMMANDS; [ elif COMMANDS; the>\n"
	". filename [arguments]                              jobs [-lnprs] [jobspec ...] or jobs -x command [>\n"
	":                                                   kill [-s sigspec | -n signum | -sigspec] pid | j>\n"
	"[ arg... ]                                          let arg [arg ...]\n"
	"[[ expression ]]                                    local [option] name[=value] ...\n"
	"alias [-p] [name[=value] ... ]                      logout [n]\n"
	"bg [job_spec ...]                                   mapfile [-d delim] [-n count] [-O origin] [-s co>\n"
	"bind [-lpsvPSVX] [-m keymap] [-f filename] [-q na>  popd [-n] [+N | -N]\n"
	"break [n]                                           printf [-v var] format [arguments]\n"
	"builtin [shell-builtin [arg ...]]                   pushd [-n] [+N | -N | dir]\n"
	"caller [expr]                                       pwd [-LP]\n"
	"case WORD in [PATTERN [| PATTERN]...) COMMANDS ;;>  read [-ers] [-a array] [-d delim] [-i text] [-n >\n"
	"cd [-L|[-P [-e]] [-@]] [dir]                        readarray [-n count] [-O origin] [-s count] [-t]>\n"
	"command [-pVv] command [arg ...]                    readonly [-aAf] [name[=value] ...] or readonly >\n"
	"compgen [-abcdefgjksuv] [-o option] [-A action] [>  return [n]\n"
	"complete [-abcdefgjksuv] [-pr] [-DE] [-o option] >  select NAME [in WORDS ... ;] do COMMANDS; done\n"
	"compopt [-o|+o option] [-DE] [name ...]             set [-abefhkmnptuvxBCHP] [-o option-name] [--] [>\n"
	"continue [n]                                        shift [n]\n"
	"coproc [NAME] command [redirections]                shopt [-pqsu] [-o] [optname ...]\n"
	"declare [-aAfFgilnrtux] [-p] [name[=value] ...]     source filename [arguments]\n"
	"dirs [-clpv] [+N] [-N]                              suspend [-f]\n"
	"disown [-h] [-ar] [jobspec ... | pid ...]           test [expr]\n"
	"echo [-neE] [arg ...]                               time [-p] pipeline\n"
	"enable [-a] [-dnps] [-f filename] [name ...]        times\n"
	"eval [arg ...]                                      trap [-lp] [[arg] signal_spec ...]\n"
	"exec [-cl] [-a name] [command [arguments ...]] [r>  true\n"
	"exit [n]                                            type [-afptP] name [name ...]\n"
	"export [-fn] [name[=value] ...] or export -p        typeset [-aAfFgilnrtux] [-p] name[=value] ...\n"
	"false                                               ulimit [-SHabcdefiklmnpqrstuvxPT] [limit]\n"
	"fc [-e ename] [-lnr] [first] [last] or fc -s [pat>  umask [-p] [-S] [mode]\n"
	"fg [job_spec]                                       unalias [-a] name [name ...]\n"
	"for NAME [in WORDS ... ] ; do COMMANDS; done        unset [-f] [-v] [-n] [name ...]\n"
	"for (( exp1; exp2; exp3 )); do COMMANDS; done       until COMMANDS; do COMMANDS; done\n"
	"function name { COMMANDS ; } or name () { COMMAND>  variables - Names and meanings of some shell var>\n"
	"getopts optstring name [arg]                        wait [-n] [id ...]\n"
	"hash [-lr] [-p pathname] [-dt] [name ...]           while COMMANDS; do COMMANDS; done\n"
	"help [-dms] [pattern ...]                           { COMMANDS ; }\n";

static char const * const TAB_HELP[] = {
	"echo",
	"help",
	"alias",
	"unalias",
	"true",
	"false",
	"pwd"
};

static char const * const TAB_MSG[] = {
	HELP_ECHO,
	HELP_HELP,
	HELP_ALIAS,
	HELP_UNALIAS,
	HELP_TRUE,
	HELP_FALSE,
	HELP_PWD
};

static const int NB_HELP = 7;

#endif
