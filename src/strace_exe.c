/*
** EPITECH PROJECT, 2019
** strace_exe
** File description:
** jooyoung.kim@epitech.eu
*/

#include <stdio.h>
#include <signal.h>
#include <sys/ptrace.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/user.h>
#include "strace.h"

pid_t *global_pid;

void handler(int sig)
{
    ptrace(PTRACE_DETACH, *global_pid, NULL, NULL);
    ptrace(PTRACE_CONT, *global_pid, NULL, NULL);
    dprintf(2, "strace: Process %d detached\n", *global_pid);
    exit (0);
}

int strace_exe(argument_t arg, char **av)
{
    pid_t pid;
    int pid_stat;

    global_pid = &pid;
    signal(SIGINT, &handler);
    signal(SIGTERM, &handler);
    signal(SIGQUIT, &handler);
    pid = fork();
    if (pid == 0) {
        if ((ptrace(PTRACE_TRACEME, NULL, NULL, NULL)) == -1)
            return (0);
        kill(getpid(), SIGSTOP);
        return (execvp(arg.content, av + 1));
    } else
        waitpid(pid, &pid_stat, 0);
    return (analyse_trace(pid, &pid_stat, arg.type));
}
