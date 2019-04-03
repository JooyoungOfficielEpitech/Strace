/*
** EPITECH PROJECT, 2019
** main.c for the project
** File description:
** jooyoung.kim@epitech.eu
*/

#include "../include/strace.h"
#include <string.h>

int check_args(char **av)
{
    if (strcmp(av[1], "--help") == 0) {
        printf("USAGE:\t./strace [-s] [-p <pid>|<command>]\n");
        return (0);
    } else if (strcmp(av[1], "-s") == 0) {
        printf("-s\n");
        return (1);
    } else if (strcmp(av[1], "-p" /*&& av2 == valid pid*/) == 0) {
        printf("-p\n");
        return (2);
    }
    return (3);
}

int main(int ac, char **av)
{
    argument_t arg;

    if (ac != 1)
        check_args(av);
    arg.content = av[1];
    arg.pid = 0;
    arg.type = EXE;
    strace_exe(arg, av);
    return (0);
}
