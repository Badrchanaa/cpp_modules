CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 #-g3 -fsanitize=address
NAME = serialize
SRCS = main.cpp Data.cpp Serializer.cpp
HEADERS = Data.hpp Serializer.hpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean clean re
