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

#include "phonebook.hpp"

int main(void)
{
    PhoneBook pb;
    std::string input;

    while (true)
    {
        std::cout << "(ADD, SEARCH, EXIT)?: ";
        if (!std::getline(std::cin, input))
        {
            std::cout << std::endl;
            break;
        }
        input.erase(0, input.find_first_not_of(" \t"));
        input.erase(input.find_last_not_of(" \t") + 1);
        if (input == "ADD")
            pb.addContact();
        else if (input == "SEARCH")
            pb.displayContacts();
        else if (input == "EXIT")
            break;
        if (std::cin.eof())
        {
            std::cout << std::endl;
            break;
        }
    }
    return (0);
}
