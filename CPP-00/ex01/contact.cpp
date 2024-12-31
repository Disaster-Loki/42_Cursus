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

void Contact::setField(const std::string &fieldName, const std::string &value) {
    if (fieldName == "firstName") firstName = value;
    else if (fieldName == "lastName") lastName = value;
    else if (fieldName == "nickName") nickName = value;
    else if (fieldName == "phoneNumber") phoneNumber = value;
    else if (fieldName == "darkestSecret") darkestSecret = value;
}

std::string Contact::getField(const std::string &fieldName) const {
    if (fieldName == "firstName") return (firstName);
    else if (fieldName == "lastName") return (lastName);
    else if (fieldName == "nickName") return (nickName);
    else if (fieldName == "phoneNumber") return (phoneNumber);
    else if (fieldName == "darkestSecret") return (darkestSecret);
    return ("");
}
