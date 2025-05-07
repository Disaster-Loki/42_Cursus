# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 16:21:04 by sde-carv          #+#    #+#              #
#    Updated: 2025/04/30 16:21:05 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= btc
CPP			= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
SRC			= main.cpp BitcoinExchange.cpp
OBJ			= $(SRC:.cpp=.o)
all: $(NAME)
$(NAME): $(OBJ)
		 $(CPP) $(FLAGS) -o $(NAME) $(OBJ)
%.o: %.cpp
	$(CPP) $(FLAGS) -c $<
clean:
		rm -f $(OBJ)
fclean: clean
		rm -f $(NAME)
re: 	fclean all
