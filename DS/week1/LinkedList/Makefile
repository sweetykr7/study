NAME = linkedList
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c createLinkedList.c addLLElement.c \
	removeLLElement.c getLLElement.c clearLinkedList.c \
	getLinkedListLength.c deleteLinkedList.c

OBJS = $(SRC:.c=.o)

%o : %c
	$(CC) -c $< -o $@

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