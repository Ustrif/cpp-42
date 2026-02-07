SRCS = main.cpp ScalarConverter.cpp
CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = convert

all: $(NAME)

$(NAME): $(SRCS)
	$(CXX) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re