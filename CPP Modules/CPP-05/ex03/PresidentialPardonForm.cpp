/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:25:17 by sde-carv          #+#    #+#             */
/*   Updated: 2025/03/25 13:25:19 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), target(target)
{
    std::cout << "PresidentialPardonForm construtor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
: AForm(copy)
{
    *this = copy;
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    if (this != &copy)
    {
        this->target = copy.target;
        std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
    }
    return (*this);
}

AForm* PresidentialPardonForm::CreateForm(const std::string &target)
{
    return (new PresidentialPardonForm(target));
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!this->isSigned())  
        throw AForm::GradeTooLowException();
    
    if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooLowException();

    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox.\n";
}

