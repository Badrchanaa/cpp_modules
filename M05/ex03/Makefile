CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address
NAME = intern
SRCS = main.cpp Bureaucrat.cpp AForm.cpp PresedentialPardonForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp Intern.cpp
HEADERS = Bureaucrat.hpp AForm.hpp PresedentialPardonForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp Intern.hpp

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o $@

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all
