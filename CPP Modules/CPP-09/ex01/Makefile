# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 16:23:50 by sde-carv          #+#    #+#              #
#    Updated: 2025/04/30 16:23:51 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= RPN
CPP				= c++ 
FLAGS		= -Wall -Wextra -Werror -std=c++98
SRC				= main.cpp RPN.cpp
OBJ				= $(SRC:.cpp=.o)
all: $(NAME)
$(NAME): $(OBJ)
		 $(CPP) $(FLAGS) -o $(NAME) $(OBJ)
%.o: %.cpp
	 $(CPP) $(FLAGS) -c $<
clean:
		rm -f $(OBJ)
fclean: clean
		rm -f $(NAME)
re: fclean all