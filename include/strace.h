/*
** EPITECH PROJECT, 2019
** jooyoung.kim
** File description:
** header file of the strace
*/

#ifndef STRACE_H_
#define STRACE_H_

#include <sys/types.h>
#include <stdio.h>
#include <sys/user.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "linux_system_call.h"

typedef struct print_argument_s
{
    int idx;
    void (*printer)(struct user_regs_struct *, linux_syscall_t);
}print_argument_t;

typedef enum e_args
{
    S,
    P,
    EXE,
    UNDEFINED
} t_args;

typedef struct arguments_s
{
    char *content;
    pid_t pid;
    t_args type;
} argument_t;

int strace_exe(argument_t arg, char **av);
int analyse_trace(pid_t pid, int *pid_stat, t_args type);
void print_arguments(struct user_regs_struct *, linux_syscall_t);
void print_return(struct user_regs_struct *, linux_syscall_t, pid_t);
void print_two_arguments(struct user_regs_struct *regs, linux_syscall_t target);
void print_three_arguments(struct user_regs_struct *regs,
linux_syscall_t target);
void print_four_arguments(struct user_regs_struct *regs,
linux_syscall_t target);
void print_five_arguments(struct user_regs_struct *regs,
linux_syscall_t target);
void print_six_arguments(struct user_regs_struct *regs, linux_syscall_t target);

#endif /* !STRACE_H_ */
