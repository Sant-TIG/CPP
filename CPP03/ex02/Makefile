NAME = fragtrap

SRCS = ClapTrap.cpp\
       FragTrap.cpp\
       ScavTrap.cpp\
       main.cpp\

OBJS = ClapTrap.o\
       FragTrap.o\
       ScavTrap.o\
       main.o\

CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

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