CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = attack
SRCS = Weapon.cpp main.cpp HumanA.cpp HumanB.cpp
HEADERS = HumanA.hpp HumanB.hpp Weapon.hpp

all: $(NAME)

$(NAME): $(CFILES) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o $@

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all