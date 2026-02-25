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

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <iostream>
#include <cstdlib>

class PhoneBook
{
    private:
        Contact contact[8];
        int     index;
    public:
        PhoneBook();
        void addContact();
        void displayContacts();
        void displayContentContact(int index);
};

#endif