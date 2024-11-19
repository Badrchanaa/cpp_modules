CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = zombies
CFILES = Zombie.cpp main.cpp randomChump.cpp newZombie.cpp
HEADERS = Zombie.hpp

all: $(NAME)

$(NAME): $(CFILES)
	$(CC) $(CFLAGS) $(CFILES) -o $@

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all