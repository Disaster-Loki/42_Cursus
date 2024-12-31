/***************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/27 11:52:18 by sde-carv          #+#    #+#              #
#    Updated: 2024/12/27 20:40:02 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"

int main(void)
{
    PhoneBook pb;
    std::string input;
    while (1)
    {
        std::cout << "(ADD, SEARCH, EXIT)?: ";
        std::getline(std::cin, input);
        if (input.empty())
         {
            std::cout << "Input cannot be empty!" << std::endl;
        }
        if (!input.empty())
        {
            if (input == "ADD") pb.addContact();
            if (input == "SEARCH") pb.displayContacts();
            if (input == "EXIT")
            {
                std::cout << "Exiting program..." << std::endl;
                break;
            }
        }
    }
    return (0);
}