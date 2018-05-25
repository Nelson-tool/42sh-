/*
** EPITECH PROJECT, 2018
** help
** File description:
** help for help
*/

#ifndef HELP_H
#define HELP_H_

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
	"GNU bash, version 4.4.12(1)-release (x86_64-redhat-linux-gnu)\n"
	"These shell commands are defined internally.  Type `help' to see this list.\n"
	"Type `help name' to find out more about the function `name'.\n"
	"Use `info bash' to find out more about the shell in general.\n"
	"Use `man -k' or `info' to find out more about commands not in this list. \n"
	
	"A star (*) next to a name means that the command is disabled.\n"
	
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

static const char  HELP_ENV[] =
	"env: env [-neE] [arg ...]\n"
	"\tSet each NAME to VALUE in the environment and run COMMAND.\n"
	"\tMandatory  arguments  to  long  options are mandatory for short options"
	"\ttoo.\n" 
	"\t-i, --ignore-environment\n"
	"\tstart with an empty environment\n"
	"\t-0, --null\n"
	"\tend each output line with NUL, not newline\n"
	"\t-u, --unset=NAME\n"
	"\tremove variable from the environment\n"
	"\t--help display this help and exit\n"
	"\t--version\n"
	"\toutput version information and exit\n"
	"\tA mere - implies -i.  If no COMMAND, print the resulting environment.\n";

static const char HELP_SETENV[] =
	"setenv: setenv [arg ...]\n"
	"DESCRIPTION\n"
	"\tThe  setenv()  function  adds the variable name to the environment with\n"
	"\tthe value value, if name does not already exist.  If name does exist in\n"
	"\tthe  environment,  then  its  value is changed to value if overwrite is\n"
	"\tnonzero; if overwrite is zero, then the value of name  is  not  changed\n"
	"\t(and setenv() returns a success status).  This function makes copies of\n";

static const char HELP_UNSETENV[] =
	"unsetenv: setenv [arg ...]\n"
	"DESCRIPTION\n"
	"\tThe unsetenv() function deletes the variable name from the environment.\n"
	"\tIf  name does not exist in the environment, then the function succeeds, \n"
	"\tand the environment is unchanged.\n";

static const char HELP_EXIT[] =
	"exit: exit [n] Exit the shell.\n"
	"Exits the shell with a status of N. If N is omitted, the exit status \n"
	"\tis that of the last command executed.\n";
static const char HELP_FG[] =
	"fg: fg [job_spec] \n"
	"\tMove job to the foreground.\n"
	"\tPlace the job identified by JOB_SPEC in the foreground, making it the\n"
	"\tcurrent job. If JOB_SPEC is not present, the shell's notion of the\n" 
	"\tcurrent job is used.\n"
	"\tExit Status: Status of command placed in foreground, or failure if an error occurs.\n";

static const char HELP_JOBS[] =
	"jobs: jobs [-lnprs] [jobspec ...] or jobs -x command [args]\n"
	"\tDisplay status of jobs.\n"
	"\tLists the active jobs. JOBSPEC restricts output to that job.\n"
	"\tWithout options, the status of all active jobs is displayed.\n"
	"\tOptions:\n"
	"\t-l lists process IDs in addition to the normal information\n" 
	"\t-n lists only processes that have changed status since the last notification\n"
	"\t-p lists process IDs only\n" 
	"\t-r restrict output to running jobs\n"
	"\t-s restrict output to stopped jobs\n"
	"If -x is supplied, COMMAND is run after all job specifications that \n"
	"\tappear in ARGS have been replaced with the process ID of that job's process group leader.\n"
	"\tExit Status: Returns success unless an invalid option is given or an error occurs.\n" 
	"\tIf -x is used, returns the exit status of COMMAND.\n";

static const char HELP_CD[] =
	"cd: cd [-L|[-P [-e]] [-@]] [dir]\n"
	"Change the shell working directory.\n"
	"\tChange the current directory to DIR. The default DIR is the value of the \n"
	"\tHOME shell variable.\n"
	"\tThe variable CDPATH defines the search path for the directory containing\n" 
	"\tDIR. Alternative directory names in CDPATH are separated by a colon (:)\n"
	"\t. A null directory name is the same as the current directory. If DIR begins\n"
	"\twith a slash (/), then CDPATH is not used.\n";

static char const * const TAB_HELP[] = {
	"echo",
	"help",
	"alias",
	"unalias",
	"true",
	"false",
	"pwd",
	"env",
	"setenv",
	"unsetenv",
	"exit",
	"fg",
	"jobs",
	"cd",
};

static const char HELP_ERROR[] =
	"42sh: help: No help topic corresponds to << %s >>.try with << help help>>\n";

static char const * const TAB_MSG[] = {
	HELP_ECHO,
	HELP_HELP,
	HELP_ALIAS,
	HELP_UNALIAS,
	HELP_TRUE,
	HELP_FALSE,
	HELP_PWD,
	HELP_ENV,
	HELP_SETENV,
	HELP_UNSETENV,
	HELP_EXIT,
	HELP_FG,
	HELP_JOBS,
	HELP_CD,
};

static const int NB_HELP = 14;

#endif

