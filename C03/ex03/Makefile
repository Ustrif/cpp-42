SRCS = main.cpp  ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
NAME = diamond
FLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++

all: $(NAME)

$(NAME): $(SRCS)
	$(CXX) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re