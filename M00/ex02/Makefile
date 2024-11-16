CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = bank
CFILES = tests.cpp Account.cpp
HEADERS = Account.hpp

all: $(NAME)

$(NAME): $(CFILES)
	$(CC) $(CFLAGS) $(CFILES) -o $@

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all