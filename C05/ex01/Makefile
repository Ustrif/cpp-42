SRCS = main.cpp Bureaucrat.cpp Form.cpp
CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = bure

all: $(NAME)

$(NAME): $(SRCS)
	$(CXX) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re