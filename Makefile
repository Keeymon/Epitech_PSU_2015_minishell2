##
## Makefile for  in /home/picher_y/rendu/Piscine_C_bistromathique
## 
## Made by Yann Pichereau
## Login   <picher_y@epitech.net>
## 
## Started on  Mon Oct 26 14:31:56 2015 Yann Pichereau
## Last update Sun Dec  6 22:38:13 2015 Yann Pichereau
##

NAME = 		mysh

CC = 		cc

RM = 		rm -f

LIB = 		-lmy -lncurses

LIBDIR = 	-L./lib/

INCLUDE = 	-I./include/

LIBMAKE = 	lib/my/

CFLAGS += 	$(LIB) $(LIBDIR) $(INCLUDE)

CFLAGS +=	-W -Werror -Wall -Wextra -ansi -pedantic

SRCS = 		minishell1.c \
		shell.c \
		get_next_line.c \
		builtin.c \
		free_tab.c \
		my_str_to_wordtab_del.c

OBJS = 		$(SRCS:.c=.o)

all : 		lib $(NAME)

lib :
		make -C $(LIBMAKE)

$(NAME) :	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LIB) $(LIBDIR) $(INCLUDE) $(CFLAGS)

clean :
		make clean -C $(LIBMAKE)
		$(RM) $(OBJS)

fclean : 	clean
		$(RM) $(NAME)
		make fclean -C $(LIBMAKE)

re : 		fclean all

.PHONY : 	all lib fclean clean re
