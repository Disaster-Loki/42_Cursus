# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/11 12:29:14 by sde-carv          #+#    #+#              #
#    Updated: 2025/01/11 12:29:15 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = zombieHorde
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98
SRC         = main.cpp Zombie.cpp zombieHorde.cpp
OBJ         = $(SRC:.cpp=.o)
all: $(NAME)
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)
clean:	
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
