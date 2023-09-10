NAME = brain

SRCS = Animal.cpp\
       Brain.cpp\
       Cat.cpp\
       Dog.cpp\
       main.cpp\

OBJS = Animal.o\
       Brain.o\
       Cat.o\
       Dog.o\
       main.o\

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