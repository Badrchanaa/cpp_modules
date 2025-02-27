CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = zombies
SRCS = Zombie.cpp main.cpp randomChump.cpp newZombie.cpp
HEADERS = Zombie.hpp

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o $@

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all