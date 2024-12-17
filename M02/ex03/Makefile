CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = bsp
CFILES = main.cpp Fixed.cpp Point.cpp bsp.cpp

all: $(NAME)

$(NAME): $(CFILES)
	$(CC) $(CFLAGS) $(CFILES) -I./ -o $@

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all