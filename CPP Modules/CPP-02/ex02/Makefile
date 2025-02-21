# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/11 11:13:33 by sde-carv          #+#    #+#              #
#    Updated: 2025/01/11 11:36:08 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Fixed
CXX	= c++
CXXFLAGS  = -Wall -Wextra -Werror -std=c++98

SRC	= main.cpp Fixed.cpp

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
