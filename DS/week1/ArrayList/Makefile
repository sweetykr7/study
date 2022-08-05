NAME = ArrayList
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c createArrayList.c deleteArrayList.c isArrayListFull.c \
	addALElement.c removeALElement.c getALElement.c \
	displayArrayList.c clearArrayList.c getArrayListLength.c

OBJS = $(SRC:.c=.o)

%o : %c
	$(CC) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $^ -o arrayList

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean :	
	make clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re 