##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile -- project
##

SRC 		= 	main.c \
				src/utils.c \
				src/solver.c \
				src/linked_list.c \
				src/get_maze_file.c \
				src/get_real_path.c \

OBJ		=	$(SRC:.c=.o)

NAME 		=	solver

RM 		=	rm -f

RM_TRASH=	*.o *~ *.gcno *.gcda libmy.a *.gch

CFLAGS	= 	-pedantic -Wall -Wextra -W -g -O2 -lm -lncurses

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(RM_TRASH)
	cd include && $(RM) $(RM_TRASH)
	cd src && $(RM) $(RM_TRASH)

fclean: clean
	$(RM) $(NAME)

re: fclean all
