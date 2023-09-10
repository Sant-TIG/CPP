NAME = animal

SRCS = Animal.cpp\
       Cat.cpp\
       Dog.cpp\
       main.cpp\
       WrongAnimal.cpp\
       WrongCat.cpp\

OBJS = Animal.o\
       Cat.o\
       Dog.o\
       main.o\
       WrongAnimal.o\
       WrongCat.o\

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