/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:24:13 by sde-carv          #+#    #+#             */
/*   Updated: 2025/03/25 13:24:26 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target)
    {
         std::cout << "ShrubberyCreationForm construtor called" << std::endl;
    }

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!this->isSigned())
        throw AForm::GradeTooLowException();
    
    if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooLowException();

    std::ofstream outfile(this->target + "_shrubbery");
    if (!outfile)
    {
        std::cerr << "Error: Could not create file" << std::endl;
        return;
    }

    outfile << "     ccee88oo\n"
               "  C8O8O8Q8PoOb o8oo\n"
               " dOB69QO8PdUOpugoO9bD\n"
               "CgggbU8OU qOp qOdoUOdcb\n"
               "   6OuU  /p u gcoUodpP\n"
               "      \\//  /douUP\n"
               "        \\////\n"
               "         |||/\\\n"
               "         |||\\/\n"
               "         |||||\n"
               "   .....//||||\\....\n";
    outfile.close();

    std::cout << executor.getName() << " executed ShrubberyCreationForm and created " 
              << this->target << "_shrubbery file.\n";
}
