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
#include <string>

PhoneBook::PhoneBook():index(0) {}

bool is_number(const std::string &str)
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

bool contains_space_tab(const std::string& input)
{
    std::string copy = input;
    copy.erase(0, copy.find_first_not_of(" \t"));
    copy.erase(copy.find_last_not_of(" \t") + 1);
    return copy.empty();
}

bool is_valid_name(const std::string& name) {
    if (contains_space_tab(name))
    {
    	std::cout << "    Parameter empty!" << std::endl;
    	return false;
    }
    for (size_t i = 0; i < name.length(); i++)
    {
        if (std::isdigit(name[i]))
        {
        	std::cout << "    Invalid charater in input!!" << std::endl;
        	return false;
        }
    }
    return true;
}

bool is_valid_phone_number(const std::string& number)
{
    int num = 0;
    if (contains_space_tab(number))
    {
    	std::cout << "    Parameter empty!" << std::endl;
    	return false;
    }
    for (size_t i = 0; i < number.length(); i++)
    {
        char c = number[i];
        if (!std::isdigit(c) && c != '+' && c != '-' && c != ' ' && c != '(' && c != ')')
        {
            std::cout << "    Invalid number !!" << std::endl;
            return (false);
        }
    }
    for (size_t i = 0; i < number.length(); i++)
    {
        char c = number[i];
        if (c != '+' && c != '-' && c != ' ' && c != '(' && c != ')')
            num++;
    }
    if (num > 15)
    {
        std::cout << "    Maximum digits reached !!" << std::endl;
        return (false);
    }
    return (true);
}

void PhoneBook::addContact()
{
    Contact new_contact;
    std::string input;

    std::cout << "   ========================================" << std::endl;
    std::cout << "   |              ADD CONTACT             |" << std::endl;
    std::cout << "   ========================================" << std::endl;
    std::cout << "    First Name: ";
    std::getline(std::cin, input);
    if (std::cin.eof())
    	return ;
    if (!is_valid_name(input))
    	return ;
    new_contact.setField("firstName",input);

    std::cout << "    Last Name: ";
    std::getline(std::cin, input);
    if (std::cin.eof())
    	return ;
    if (!is_valid_name(input))
    	return;
    new_contact.setField("lastName",input);

    std::cout << "    Nickname: ";
    std::getline(std::cin, input);
    if (std::cin.eof())
    	return ;
    if (contains_space_tab(input))
    	return ;
    new_contact.setField("nickName",input);

    std::cout << "    Phone Number: ";
    std::getline(std::cin, input);
    if (std::cin.eof())
    	return ;
    if (!is_valid_phone_number(input))
    	return ;
    new_contact.setField("phoneNumber",input);

    std::cout << "    Darkest Secret: ";
    std::getline(std::cin, input);
    if (std::cin.eof())
    	return ;
    if (contains_space_tab(input))
    	return ;
    new_contact.setField("darkestSecret",input);

    std::cout << "   ========================================" << std::endl;

    contact[index] = new_contact;
    index = (index + 1) % 8;
    std::cout << "                 SUCCESSFULL" << std::endl << std::endl;
}

std::string truncate(const std::string &str) {
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

void PhoneBook::displayContacts()
{
    int i;
    int	index;
    std::string str;

    i = -1;
    std::cout << "   ==========================================" << std::endl;
    std::cout << "   |              CONTACT LIST              |" << std::endl;
    std::cout << "   ==========================================" << std::endl;
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
    std::cout << "   ==========================================" << std::endl;
    std::cout << std::endl << "Index: ";
    std::getline(std::cin, str);
    if (std::cin.eof())
        return ;
    if (contains_space_tab(str))
    {
    	std::cout << "Parameter empty!" << std::endl;
    	return ;
    }
    if (!is_number(str))
    {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    index = std::atoi(str.c_str());
    displayContentContact(index);
}

void PhoneBook::displayContentContact(int ind)
{
    if (ind < 0 || ind >= 8 || contact[ind].getField("firstName").empty())
    {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    std::cout << " ================================" << std::endl;
    std::cout << " |            CONTACT           |" << std::endl;
    std::cout << " ===============================" << std::endl;
    std::cout << "  First Name: " << contact[ind].getField("firstName") << std::endl;
    std::cout << "  Last Name: " << contact[ind].getField("lastName") << std::endl;
    std::cout << "  Nickname: " << contact[ind].getField("nickName") << std::endl;
    std::cout << "  Phone Number: " << contact[ind].getField("phoneNumber") << std::endl;
    std::cout << "  Darkest Secret: " << contact[ind].getField("darkestSecret") << std::endl;
    std::cout << " ================================" << std::endl << std::endl;
}
