CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address
NAME = Span
SRCS = main.cpp tests.cpp Span.cpp
HEADERS = tests.hpp Span.hpp

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o $@

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

