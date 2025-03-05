CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 #-g3
NAME = animals
SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp
HEADERS = Animal.hpp Dog.hpp Cat.hpp Brain.hpp

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o $@

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all
