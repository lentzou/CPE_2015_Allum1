##
## Makefile for makefile in /home/lentz_f/rendu/projet/CPE_2015_Allum1
##
## Made by florian lentz
## Login   <lentz_f@epitech.net>
##
## Started on  Thu Jul 14 15:54:49 2016 florian lentz
## Last update Thu Jul 21 18:03:50 2016 florian lentz
##

NAME	= allum1

SRC	= src/get_next_line_bonus.c \
	  src/check_error_bonus.c \
	  src/functions_bonus.c \
	  src/main_bonus.c \
	  src/ai_bonus.c \
	  src/player2.c \
	  src/bonus.c

OBJ	= $(SRC:.c=.o)

CFLAGS	+= -W -Werror -Wall -I./include

RM	= rm -rf

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
