/*
** EPITECH PROJECT, 2019
** definition of all printing function of the trace
** File description:
** jooyoung.kim@epitech.eu
*/

#include "../include/strace.h"

void print_two_arguments(struct user_regs_struct *regs, linux_syscall_t target)
{
    if (regs) {
        dprintf(2, "0x%llx, 0x%llx", regs->rdi, regs->rsi);
    }
}

void print_three_arguments(struct user_regs_struct *regs,
linux_syscall_t target)
{
    if (regs) {
        dprintf(2, "0x%llx, 0x%llx, 0x%llx", regs->rdi, regs->rsi, regs->rdx);
    }
}

void print_four_arguments(struct user_regs_struct *regs, linux_syscall_t target)
{
    if (regs) {
        dprintf(2, "0x%llx, 0x%llx, 0x%llx, 0x%llx",
        regs->rdi, regs->rsi, regs->rdx, regs->r8);
    }
}

void print_five_arguments(struct user_regs_struct *regs, linux_syscall_t target)
{
    if (regs) {
        dprintf(2, "0x%llx, 0x%llx, 0x%llx, 0x%llx, 0x%llx",
        regs->rdi, regs->rsi, regs->rdx, regs->r8, regs->r9);
    }
}

void print_six_arguments(struct user_regs_struct *regs, linux_syscall_t target)
{
    if (regs) {
        dprintf(2, "0x%llx, 0x%llx, 0x%llx, 0x%llx, 0x%llx, 0x%llx",
        regs->rdi, regs->rsi, regs->rdx, regs->r8, regs->r9, regs->r10);
    }
}
