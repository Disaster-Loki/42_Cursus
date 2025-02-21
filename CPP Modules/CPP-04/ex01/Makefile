# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/20 09:37:46 by sde-carv          #+#    #+#              #
#    Updated: 2025/02/20 09:37:48 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Animal
CXX	= c++
CXXFLAGS  = -Wall -Wextra -Werror -std=c++98
SRC	= main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
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
