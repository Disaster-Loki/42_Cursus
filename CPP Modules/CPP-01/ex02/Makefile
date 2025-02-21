# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/11 12:12:18 by sde-carv          #+#    #+#              #
#    Updated: 2025/01/11 12:16:26 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= main
CXX		= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
SRC		= main.cpp
OBJ		= $(SRC:.cpp=.o)
all: $(NAME)
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)
clean:	
	rm -f $(OBJ)
fclean:
	rm -f $(OBJ)
	rm -f $(NAME)
re: fclean all
