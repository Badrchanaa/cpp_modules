CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = firstCanon
SRCS = main.cpp Fixed.cpp
HEADERS = Fixed.hpp

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o $@

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all