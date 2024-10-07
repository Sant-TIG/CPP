NAME = forms

SRCS = AForm.cpp\
       Bureaucrat.cpp\
       main.cpp\
       PresidentialPardonForm.cpp\
       RobotomyRequestForm.cpp\
       ShrubberyCreationForm.cpp\

OBJS = AForm.o\
       Bureaucrat.o\
       main.o\
       PresidentialPardonForm.o\
       RobotomyRequestForm.o\
       ShrubberyCreationForm.o\

CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

$(OBJS): %.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean all