##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makes binary and more
##

SRC	=	source/check_errors.c		\
		source/display_usage.c		\
		source/read_file.c			\
		source/enlarge.c			\
		source/copy_initial_map.c	\
		source/move_player.c		\
		source/movement.c			\
		source/reset_file.c			\
		source/manage_o.c			\
		source/victory.c			\
		source/defeat.c				\
		source/adjust_map.c			\
		source/my_sokoban.c

SRCTEST	=	tests/tests_minishell.c

NAME	=	my_sokoban

LIB_MY	=	libmy.a

UTFLAGS	=	--coverage -lcriterion

all:	binary run_tests

$(LIB_MY):
		make -sC lib/my/

binary:	$(LIB_MY)
		gcc -o $(NAME) $(SRC) main.c -I./include -L./lib -lmy -lncurses
		echo -e "\033[05m\033[44mcompilation done => ${NAME}\033[00m"

run_tests:
	gcc $(SRCTEST) $(SRC) -o unit_test $(UTFLAGS) \
	-I./include -L./lib -lmy -lncurses
	./unit_test

clean:
		make -sC lib/my/ clean
		$(shell find -name "*.gcda" -delete)
		$(shell find -name "*.gcno" -delete)
		$(shell find -name "#*#" -delete -o -name "*~" -delete)

fclean:	clean
		make -sC lib/my/ fclean
		rm -f $(NAME)
		rm -f unit_test
		clear

re:	fclean all

.PHONY:	clean fclean re all test_run
