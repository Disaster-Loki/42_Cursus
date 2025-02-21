# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 15:38:52 by sde-carv          #+#    #+#              #
#    Updated: 2025/02/12 15:38:54 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ClapTrap
CXX	= c++
CXXFLAGS  = -Wall -Wextra -Werror -std=c++98
SRC	= main.cpp ClapTrap.cpp
OBJ 	= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)
clean: 
	rm -f $(OBJ)
fclean: 
	rm -f $(OBJ)
	rm -f $(NAME)
re: fclean all
