##
## EPITECH PROJECT, 2019
## 109titration
## File description:
## makefile
##

SRC	=	main.c			\
		usage.c			\
		read_file.c		\
		check_map.c		\
		init_struct.c		\
		double.c		\
		char_to_double.c	\
		last_derivative.c

OBJ	=	$(SRC:.c=.o)

NAME	=	109titration

CFLAGS	=	-I ./include -lm -Wall -Werror -Wextra

all:		$(NAME) message

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f *~ $(NAME)

re:		fclean all

message:
		@echo "SUCCESSFULLY COMPILED!"
