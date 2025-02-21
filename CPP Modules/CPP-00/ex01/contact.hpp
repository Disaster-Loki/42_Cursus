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

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
    private:
        std::string  firstName;
        std::string  lastName;
        std::string  nickName;
        std::string  phoneNumber;
        std::string  darkestSecret;
    public:
      void  setField(const std::string &fielName, const std::string &value);
      std::string   getField(const std::string &fieldName) const;
};

#endif