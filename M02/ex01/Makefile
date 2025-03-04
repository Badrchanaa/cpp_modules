CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = fixedpoint
SRCS = main.cpp Fixed.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -I./ -o $@

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all