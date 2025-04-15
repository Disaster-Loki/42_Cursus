# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 11:57:21 by sde-carv          #+#    #+#              #
#    Updated: 2025/04/15 11:57:22 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Base
CXX		= 	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRC		=	main.cpp Base.cpp
OBJ		=	$(SRC:.cpp=.o)

all:	$(NAME)
$(NAME):	$(OBJ)
			$(CXX) $(CFLAGS) -o $(NAME) $(OBJ)
clean:
		rm -f $(OBJ)
fclean:
		rm -f $(OBJ)
		rm -f $(NAME)
re:	fclean all
