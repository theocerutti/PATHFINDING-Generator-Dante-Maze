##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile -- project
##

SRC 		= 	main.c

OBJ		=	$(SRC:.c=.o)

RM 		=	rm -f

RM_TRASH=	*.o *~ *.gcno *.gcda libmy.a *.gch *.data

CFLAGS	= 	-pedantic -Wall -Wextra -W -g -O2

all:
	make -C solver && make -C generator && make -C tournament

compile_maze:
	make -C solver && make -C generator

clean:
	$(RM) $(RM_TRASH)
	make fclean -C tournament
	make fclean -C solver
	make fclean -C generator

fclean: clean
	$(RM) $(NAME)

re: fclean all
