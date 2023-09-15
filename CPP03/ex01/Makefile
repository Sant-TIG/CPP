NAME = scavtrap

SRCS = main.cpp\
       ClapTrap.cpp\
       ScavTrap.cpp\

OBJS = main.o\
       ClapTrap.o\
       ScavTrap.o\

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