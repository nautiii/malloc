##
## EPITECH PROJECT, 2019
## PSU_2019_malloc
## File description:
## Makefile
##

CC	=	gcc

RM	=	rm -rf

DIR	=	src/

INC =	-I./include

SRC	=	$(addprefix $(DIR), malloc.c \
							realloc.c \
							free.c \
							list.c \
							oplist.c \
		)

OBJ	=	$(SRC:.c=.o)

LIB	=	libmy_malloc.so

TSRC =		tests/unit_tests.c

CRITERION =	--coverage -lcriterion

TEST =		unit_tests

all:	$(LIB)

$(LIB):	$(OBJ)
		$(CC) -shared -o $@ $(OBJ)

%.o:	%.c
		$(CC) -fpic $(INC) -W -Wall -Wextra -o $@ -c $< 

tests_run:
			$(CC) -o $(TEST) $(TSRC) $(SRC) $(INC) $(CRITERION)
			./$(TEST)
			gcovr

run:
		@$(CC) tmp/test.c -lm $(INC)
		@./tmp/run.sh
		@$(RM) a.out

test:
		@$(CC) tmp/test.c -lm $(INC)
		@valgrind --trace-children=yes --leak-check=full ./tmp/run.sh
		@$(RM) a.out

clean:
		@$(RM) $(OBJ)
		@$(RM) *.gcda
		@$(RM) *.gcno

fclean:	clean
		$(RM) $(LIB)
		$(RM) $(TEST)

re:	fclean all

.PHONY:	all	run	test	clean	fclean	re