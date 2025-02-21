# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/26 11:52:18 by sde-carv          #+#    #+#              #
#    Updated: 2024/12/26 20:40:02 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = phonebook

CXX          = c++
CXXFLAGS      = -Wall -Wextra -Werror -std=c++98

RESET       = \033[0m
RED         = \033[31m
BLUE        = \033[34m
YELLOW      = \033[33m
ORANGE      = \033[38;5;208m
GREEN       = \033[32m

SRC_FILES = main.CXX		\
			contact.CXX 	\
			phonebook.CXX 	\


OBJ_FILES = $(SRC_FILES:.CXX=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ_FILES)
	clear
	@echo "$(GREEN)COMPILATION COMPLETE$(RESET)"

clean:
	rm -f $(OBJ_FILES)
	clear
	@echo "$(ORANGE)CLEANING OBJECT FILES$(RESET)"

fclean: clean
	rm -f $(NAME)
	clear
	@echo "$(RED)ALL CLEANED$(RESET)"

re: fclean all
