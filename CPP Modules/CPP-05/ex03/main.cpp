/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 09:56:30 by sde-carv          #+#    #+#             */
/*   Updated: 2025/03/17 09:56:32 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() 
{
    // ----------- TESTING BUREAUCRAT CLASS -----------
    std::cout << "\n----- Testing Constructor with Invalid Grades -----" << std::endl;
    try 
    {
        Bureaucrat b("Alice", 151);
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try 
    {
        Bureaucrat b("Bob", 0); 
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n----- Testing Valid Bureaucrat Creation -----" << std::endl;
    Bureaucrat c("Charlie", 42);
    std::cout << c << std::endl;

    std::cout << "\n----- Testing Incrementing and Decrementing Grades -----" << std::endl;
    try 
    {
        Bureaucrat d("David", 2);
        std::cout << d << std::endl;
        d.incrementGrade();
        std::cout << "After increment: " << d << std::endl;
        d.incrementGrade();
    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }
    try 
    {
        Bureaucrat e("Eve", 149);
        std::cout << e << std::endl;
        e.decrementGrade();
        std::cout << "After decrement: " << e << std::endl;
        e.decrementGrade();
    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }

    // ----------- TESTING FORM CREATION, SIGNING AND EXECUTION -----------
    std::cout << "\n----- Testing Form Creation, Signing and Execution -----" << std::endl;

    ShrubberyCreationForm shrubberyForm("home");
    RobotomyRequestForm robotomyForm("Alice");
    PresidentialPardonForm pardonForm("Bob");
    Bureaucrat g("George", 5);
    try 
    {
        std::cout << "Attempting to execute Shrubbery Creation Form" << std::endl;
        g.executeForm(shrubberyForm);
    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }
    g.signForm(shrubberyForm);
    try 
    {
        std::cout << "Attempting to execute Shrubbery Creation Form after signing" << std::endl;
        g.executeForm(shrubberyForm);
    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }
    try 
    {
        std::cout << "Attempting to execute Robotomy Request Form" << std::endl;
        g.executeForm(robotomyForm);
    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }
    g.signForm(robotomyForm);
    try 
    {
        std::cout << "Attempting to execute Robotomy Request Form after signing" << std::endl;
        g.executeForm(robotomyForm);
    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }
    try 
    {
        std::cout << "Attempting to execute Presidential Pardon Form" << std::endl;
        g.executeForm(pardonForm);
    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }
    g.signForm(pardonForm);
    try 
    {
        std::cout << "Attempting to execute Presidential Pardon Form after signing" << std::endl;
        g.executeForm(pardonForm);
    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }

    // ----------- TESTING INTERN CLASS -----------

    std::cout << "\n----- Testing Intern Class -----" << std::endl;

    Intern someRandomIntern;
    AForm* form;

    std::cout << "\n--- Testing valid form creation ---" << std::endl;
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form) {
        std::cout << *form << std::endl; 
        delete form;
    }

    form = someRandomIntern.makeForm("presidential pardon", "Alice");
    if (!form)
    {
        std::cout << "Erro\n" << std::endl;
        return (0);
    }
    if (form) {
        std::cout << *form << std::endl; 
        delete form;
    }

    form = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (form) {
        std::cout << *form << std::endl; 
        delete form; 
    }

    std::cout << "\n--- Testing invalid form creation ---" << std::endl;
    form = someRandomIntern.makeForm("unknown form", "Test");
    if (form) {
        std::cout << *form << std::endl;
        delete form;
    }

    std::cout << "\n----- All Tests Completed -----" << std::endl;
    return 0;
}
