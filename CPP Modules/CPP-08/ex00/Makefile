# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/22 09:17:23 by sde-carv          #+#    #+#              #
#    Updated: 2025/04/22 09:17:24 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= EasyFind
CXX		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
SRC		= main.cpp
OBJ		= $(SRC:.cpp=.o)
all: 	$(NAME)
$(NAME): $(OBJ)
		$(CXX) $(CFLAGS) -o $(NAME) $(OBJ)
clean: 	
		rm -f $(OBJ)
fclean: clean
		rm -f $(NAME)
re: 	fclean all
