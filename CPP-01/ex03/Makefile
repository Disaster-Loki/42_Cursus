# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/18 12:04:05 by sde-carv          #+#    #+#              #
#    Updated: 2025/01/18 12:09:07 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= main
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
SRC			= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJ			= $(SRC:.cpp=.o)
all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
clean:
	rm -f $(OBJ)
fclean:
	rm -f $(OBJ)
	rm -f $(NAME)
re: fclean all
