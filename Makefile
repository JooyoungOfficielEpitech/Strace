##
## EPITECH PROJECT, 2019
## makefile for strace
## File description:
## jooyoung.kim@epitech.eu
##

SRC		=	src/main.c			\
			src/strace_exe.c		\
			src/analyse_trace.c		\
			src/print_argument_return.c	\
			src/print_arguments.c		\

OBJ		=	$(SRC:.c=.o)

NAME		=	strace

CC		=	gcc

CFLAGS		=	-I ./include

CPPFLAGS	=	-Wextra -Werror

RM		=	rm -rf

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

debug:		$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) -g3

.PHONY:		all clean fclean re debug
