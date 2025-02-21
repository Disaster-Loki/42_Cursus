/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:46:46 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/20 11:46:48 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain created!" << std::endl;
}

Brain::Brain(const Brain& copy)
{
    std::cout << "Brain copied!" << std::endl;
    *this = copy;
}

Brain& Brain::operator=(const Brain& copy)
{
    if (this != &copy)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = copy.ideas[i];
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destroyed!" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < 100)
        ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return (ideas[index]);
    return ("");
}
