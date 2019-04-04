##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile -- project
##

RM 		=	rm -f

RM_TRASH=	*.o *~ *.gcno *.gcda libmy.a *.gch generator solver solver_bonus generator_bonus

all:
	make -C ../solver/bonus/solver
	cp ../solver/bonus/solver/solver .
	mv solver solver_bonus
	make -C ../generator/bonus/generator
	cp ../generator/bonus/generator/generator .
	mv generator generator_bonus
	make compile_maze -C ..
	cp ../solver/solver .
	cp ../generator/generator .

clean:
	$(RM) $(RM_TRASH)

fclean: clean
	$(RM) $(RM_TRASH)

re: fclean all
