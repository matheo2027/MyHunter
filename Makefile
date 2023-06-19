##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SRC = lib/my/mini_printf.c	\
		lib/my/my_put_nbr.c	\
		lib/my/my_putstr.c	\
		lib/my/my_putchar.c	\
		lib/my/my_strlen.c	\
		src/main.c	\
		src/game_view.c	\
		src/destroy.c	\
		src/flag.c	\
		src/kill.c

OBJ = $(SRC:.c=.o)

NAME = my_hunter

all: $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) -lcsfml-graphics -lcsfml-system

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
