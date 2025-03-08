CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = scavtrap
CFILES = main.cpp ClapTrap.cpp ScavTrap.cpp
HEADERS = ClapTrap.hpp ScavTrap.hpp

all: $(NAME)

$(NAME): $(CFILES) $(HEADERS)
	$(CC) $(CFLAGS) $(CFILES) -o $@

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all