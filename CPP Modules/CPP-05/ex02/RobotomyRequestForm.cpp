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

// Construtor: inicializa AForm e armazena target
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target(target)
{
    std::srand(std::time(0)); // Inicializa o gerador de números aleatórios
}

// Destrutor
RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

// Implementação de execute()
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!this->isSigned())  
        throw AForm::GradeTooLowException();
    
    if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooLowException();

    // Simula a cirurgia de robotomização
    std::cout << "* BZZZZT... VRRRR... * (drilling noises)\n";

    if (std::rand() % 2) // 50% de chance
        std::cout << this->target << " has been successfully robotomized!\n";
    else
        std::cout << "Robotomy failed on " << this->target << "!\n";
}
