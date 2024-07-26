def generate_makefile(project_name, file_names=None):
    makefile_template = (
        "NAME = {}\n\n"
        "SRCS = {}\n\n"
        "OBJS = {}\n\n"
        "CC = c++\n\n"
        "FLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic\n\n"
        "RM = rm -rf\n\n"
        "all: $(NAME)\n\n"
        "$(NAME): $(OBJS)\n"
        "\t$(CC) $(FLAGS) $^ -o $@\n\n"
        "$(OBJS): %.o: %.cpp\n"
        "\t$(CC) $(FLAGS) -c $< -o $@\n\n"
        "clean:\n"
        "\t$(RM) $(OBJS)\n\n"
        "fclean: clean\n"
        "\t$(RM) $(NAME)\n\n"
        "re: fclean all\n\n"
        ".PHONY: fclean all"
    ).format(
        project_name,
        '\n'.join([f' ' * 7 + f'{name}.cpp\\' if i > 0 else f'{name}.cpp\\' for i,name in enumerate(file_names)]),
        '\n'.join([f' ' * 7 + f'{name}.o\\' if i > 0 else f'{name}.o\\' for i,name in enumerate(file_names)])
    )

    with open('Makefile', 'w') as makefile:
        makefile.write(makefile_template)

if __name__ == "__main__":
    project_name = input("Enter the program name: ")
    num_class = int(input("Number of files to compile: "))
    file_names = []
    for i in range(num_class):
        file_name = input(f"File name({i + 1}): ")
        file_names.append(file_name)
    generate_makefile(project_name, file_names)