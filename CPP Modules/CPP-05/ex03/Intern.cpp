/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:18:45 by sde-carv          #+#    #+#             */
/*   Updated: 2025/04/09 18:18:46 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
    std::cout << "Intern construtor called" << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern destrutor called" << std::endl;
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
    std::string forms[] = {
        "SHRUBBERY CREATION",
        "ROBOTOMY REQUEST",
        "PRESIDENTIAL PARDON"};
    
    AForm* (*functions[])(const std::string &target) = {
        ShrubberyCreationForm::CreateForm,
        RobotomyRequestForm::CreateForm,
        PresidentialPardonForm::CreateForm
    };
    for (int i = 0; i < forms->size(); i++)
    {
        if (forms[i] == name)
        {
            std::cout << "Intern creates " << name << std::endl;
            return (functions[i](target));
            
        }
    }
    std::cout << "Invalid Form\n" << std::endl;
    return (NULL);
}