CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = phonebook
CFILES = PhoneBook.cpp Contact.cpp main.cpp
HEADERS = PhoneBook.hpp Contact.hpp

all: $(NAME)

$(NAME): $(CFILES)
	$(CC) $(CFLAGS) $(CFILES) -o $@

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all