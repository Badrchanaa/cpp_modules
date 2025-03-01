CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = fragtrap
CFILES = main.cpp ClapTrap.cpp FragTrap.cpp
HEADERS = ClapTrap.hpp FragTrap.hpp

all: $(NAME)

$(NAME): $(CFILES)
	$(CC) $(CFLAGS) $(CFILES) -o $@

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all