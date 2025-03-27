CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3
NAME = array
SRCS = main.cpp
HEADERS = Array.hpp

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o $@

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all
