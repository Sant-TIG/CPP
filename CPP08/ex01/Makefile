NAME = span

SRCS = main.cpp\
       Span.cpp\

OBJS = main.o\
       Span.o\

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