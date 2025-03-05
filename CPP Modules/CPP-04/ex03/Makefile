# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/20 09:37:46 by sde-carv          #+#    #+#              #
#    Updated: 2025/02/20 09:37:48 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = Interface
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98

SRC         = main.cpp 				\
              AMateria.cpp 			\
              Ice.cpp 				\
              Cure.cpp 				\
              Character.cpp 		\
              MateriaSource.cpp		\

OBJ         = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
