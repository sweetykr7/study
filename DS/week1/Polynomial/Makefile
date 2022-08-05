NAME = polynomial
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c polynomial.c \
		createDoublyList.c deleteDoublyList.c addDLElement.c \
		removeDLElement.c clearDoublyList.c getDoublyListLength.c \
		getDLElement.c displayDoublyList.c


OBJS = $(SRC:.c=.o)

%o : %c
	$(CC) -c $< -o $@ -I includes

$(NAME) : $(OBJS)
	$(CC) $^ -o $(NAME)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean :	
	make clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re 