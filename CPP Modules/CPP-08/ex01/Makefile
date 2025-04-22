# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/22 12:19:04 by sde-carv          #+#    #+#              #
#    Updated: 2025/04/22 12:19:11 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Span
CXX		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
SRC		= main.cpp Span.cpp
OBJ		= $(SRC:.cpp=.o)
all: 	$(NAME)
$(NAME): $(OBJ)
		$(CXX) $(CFLAGS) -o $(NAME) $(OBJ)
clean: 	
		rm -f $(OBJ)
fclean: clean
		rm -f $(NAME)

re: 	fclean all

