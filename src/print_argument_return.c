/*
** EPITECH PROJECT, 2019
** contains functions for the print_arguments and print_return
** File description:
** jooyoung.kim@epitech.eu
*/

#include "../include/strace.h"

void print_one_argument(struct user_regs_struct *regs, linux_syscall_t target)
{
    if (regs) {
        dprintf(2, "0x%llx", regs->rdi);
    }
}

static print_argument_t global_printer[] =
{
    {1, &print_one_argument},
    {2, &print_two_arguments},
    {3, &print_three_arguments},
    {4, &print_four_arguments},
    {5, &print_five_arguments},
    {6, &print_six_arguments}
};

void print_arguments(struct user_regs_struct *regs, linux_syscall_t target)
{
    if (target.args != 0)
        global_printer[target.args - 1].printer(regs, target);
}

void print_return(struct user_regs_struct *regs,
linux_syscall_t target, pid_t pid)
{
    int status = 0;

    if (target.args == 0)
        dprintf(2, ") = ?\n");
    else {
        ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
        waitpid(pid, &status, 0);
        ptrace(PTRACE_GETREGS, pid, NULL, regs);
        dprintf(2, ") = 0x%llx\n", regs->rax);
    }
}
