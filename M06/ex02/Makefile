CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address
NAME = identify
SRCS = main.cpp Base.cpp
HEADERS = A.hpp B.hpp C.hpp Base.hpp

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o $@

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all
