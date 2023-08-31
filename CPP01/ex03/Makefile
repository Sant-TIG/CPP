NAME = unnecessaryViolence

SRCS = HumanA.cpp\
       HumanB.cpp\
       main.cpp\
       Weapon.cpp\

OBJS = HumanA.o\
       HumanB.o\
       main.o\
       Weapon.o\

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