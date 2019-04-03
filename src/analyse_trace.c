/*
** EPITECH PROJECT, 2019
** jooyoung.kim@epitech.eu
** File description:
** analyse_trace
*/

#include "../include/strace.h"

void print_regs(pid_t pid, struct user_regs_struct *regs, int *pid_stat)
{
    linux_syscall_t target;
    int i = 0;
    int rax = regs->rax;

    if (!regs)
        return;
    while (i != 328) {
        if (rax == system_table[i].rax) {
            target = system_table[i];
            break;
        }
        i++;
    }
    if (i >= 328)
        return;
    dprintf(2, "%s(", target.name);
    print_arguments(regs, target);
    print_return(regs, target, pid);
}

int analyse_trace(pid_t pid, int *pid_stat, t_args type)
{
    struct user_regs_struct regs;
    unsigned short check = 1;

    while (WIFSTOPPED(*pid_stat)
    && WSTOPSIG(*pid_stat) == SIGTRAP
    || WSTOPSIG(*pid_stat) == SIGSTOP) {
        ptrace(PTRACE_GETREGS, pid, NULL, &regs);
        check = ptrace(PTRACE_PEEKTEXT, pid, regs.rip, NULL);
        ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
        waitpid(pid, pid_stat, 0);
        if (check == 0x80CD || check == 0x50F)
            print_regs(pid, &regs, pid_stat);
    }
    printf("process finished\n");
    return (0);
}
