##
## Makefile for makefile in /home/lentz_f/rendu/projet/CPE_2015_Allum1
##
## Made by florian lentz
## Login   <lentz_f@epitech.net>
##
## Started on  Thu Jul 14 15:54:49 2016 florian lentz
## Last update Thu Jul 21 18:02:00 2016 florian lentz
##

NAME	= allum1

SRC	= src/get_next_line.c \
	  src/check_error.c \
	  src/functions.c \
	  src/main.c \
	  src/ai.c

OBJ	= $(SRC:.c=.o)

CFLAGS	+= -Wextra -Werror -Wall -I./include

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
