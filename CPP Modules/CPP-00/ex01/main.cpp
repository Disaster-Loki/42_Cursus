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
        if (std::cin.eof())
        {
            std::cout << "\nExiting program cleanly..." << std::endl;
            break;
        }
        input.erase(0, input.find_first_not_of(" \t"));
        input.erase(input.find_last_not_of(" \t") + 1);
        if (input.empty())
        {
            std::cout << "Input cannot be empty!" << std::endl;
            continue;
        }
        if (input == "ADD")
            pb.addContact();
        else if (input == "SEARCH")
            pb.displayContacts();
        else if (input == "EXIT")
        {
            std::cout << "Exiting program..." << std::endl;
            break;
        }
        if (std::cin.eof())
        {
            std::cout << "\nExiting program cleanly..." << std::endl;
            break;
        }   
    }
    return (0);
}
