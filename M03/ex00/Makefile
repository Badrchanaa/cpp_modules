CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = claptrap
SRCS = ClapTrap.cpp main.cpp
HEADERS = ClapTrap.hpp

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o $@

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all
