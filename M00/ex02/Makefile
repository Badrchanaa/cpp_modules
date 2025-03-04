CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = bank
SRCS = tests.cpp Account.cpp
HEADERS = Account.hpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $@

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all