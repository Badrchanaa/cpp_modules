CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Harl
CFILES = main.cpp Harl.cpp
HEADERS =  Harl.hpp

all: $(NAME)

$(NAME): $(CFILES)
	$(CC) $(CFLAGS) $(CFILES) -o $@

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all