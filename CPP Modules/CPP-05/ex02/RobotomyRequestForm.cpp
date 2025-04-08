/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:25:03 by sde-carv          #+#    #+#             */
/*   Updated: 2025/03/25 13:25:05 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target(target)
{
    std::srand(std::time(0));
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!this->isSigned())  
        throw AForm::GradeTooLowException();
    
    if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooLowException();

    std::cout << "* BZZZZT... VRRRR... * (drilling noises)\n";

    if (std::rand() % 2)
        std::cout << this->target << " has been successfully robotomized!\n";
    else
        std::cout << "Robotomy failed on " << this->target << "!\n";
}
