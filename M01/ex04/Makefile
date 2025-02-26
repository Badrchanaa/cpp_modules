CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = mySed
SRCS = main.cpp
HEADERS =

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $@

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all


