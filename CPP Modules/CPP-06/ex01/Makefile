# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 11:42:30 by sde-carv          #+#    #+#              #
#    Updated: 2025/04/15 11:42:31 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Serializer
CXX		= 	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRC		=	main.cpp Serializer.cpp
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

