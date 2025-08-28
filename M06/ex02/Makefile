CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 #-g3 -fsanitize=address
NAME = identify
SRCS = main.cpp Base.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = A.hpp B.hpp C.hpp Base.hpp

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
