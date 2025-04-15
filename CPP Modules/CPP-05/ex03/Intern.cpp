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

const std::string megaforne(const std::string &str)
{
    std::string str2;
    for (int i = 0; i < str.size(); i++)
        str2 += std::tolower(str[i]);
    return (str2);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
    const std::string str = megaforne(name);
    std::string forms[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"};
    
    AForm* (*functions[])(const std::string &target) = {
        &ShrubberyCreationForm::CreateForm,
        &RobotomyRequestForm::CreateForm,
        &PresidentialPardonForm::CreateForm
    };
    for (int i = 0; i < 3; i++)
    {
        if (forms[i] == str)
        {
            std::cout << "Intern creates " << str << std::endl;
            return (functions[i](target));
        }
    }
    std::cout << "Invalid Form\n" << std::endl;
    return (NULL);
}