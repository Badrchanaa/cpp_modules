CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = bsp
SRCS = main.cpp Fixed.cpp Point.cpp bsp.cpp
HEADERS = Fixed.hpp Point.hpp

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -I./ -o $@

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all