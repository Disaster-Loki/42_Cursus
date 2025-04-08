# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 09:56:21 by sde-carv          #+#    #+#              #
#    Updated: 2025/03/17 09:56:23 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Bureaucrat
CXX		= 	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRC		=	main.cpp 							\
			AForm.cpp 							\
			Bureaucrat.cpp 						\
			PresidentialPardonForm.cpp			\
			RobotomyRequestForm.cpp				\
			ShrubberyCreationForm.cpp
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

