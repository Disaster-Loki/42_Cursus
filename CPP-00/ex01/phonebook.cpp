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
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook():index(0) {}

void PhoneBook::addContact()
{
    Contact new_contact;
    std::string input;

    std::cout << "First Name: ";
    std::getline(std::cin, input);
    new_contact.setField("firstName",input);

    std::cout << "Last Name: ";
    std::getline(std::cin, input);
    new_contact.setField("lastName",input);

    std::cout << "Nickname: ";
    std::getline(std::cin, input);
    new_contact.setField("nickName",input);

    std::cout << "Phone Number: ";
    std::getline(std::cin, input);
    new_contact.setField("phoneNumber",input);

    std::cout << "Darkest Secret: ";
    std::getline(std::cin, input);
    new_contact.setField("darkestSecret",input);

    contact[index] = new_contact;
    index = (index + 1) % 8;
}

std::string truncate(const std::string &str) {
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

void PhoneBook::displayContacts()
{
    int i;
    int index;

    i = -1;
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    while (++i < 8)
    {
        if (contact[i].getField("firstName").empty()) continue;

        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncate(contact[i].getField("firstName")) << "|"
                  << std::setw(10) << truncate(contact[i].getField("lastName")) << "|"
                  << std::setw(10) << truncate(contact[i].getField("nickName")) << std::endl;
    }
    std::cout << std::endl << "Index: ";
    std::cin >> index;
    std::cin.ignore();
    displayContentContact(index);
}

void PhoneBook::displayContentContact(int indexx)
{
    if (indexx < 0 || indexx >= 8 || contact[indexx].getField("firstName").empty() || indexx >= index)
    {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    std::cout << "First Name: " << contact[indexx].getField("firstName") << std::endl;
    std::cout << "Last Name: " << contact[indexx].getField("LastName") << std::endl;
    std::cout << "Nickname: " << contact[indexx].getField("nickName") << std::endl;
    std::cout << "Phone Number: " << contact[indexx].getField("phoneNumber") << std::endl;
    std::cout << "Darkest Secret: " << contact[indexx].getField("darkestSecret") << std::endl << std::endl;
}
