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

    // ----------- TESTING FORM CREATION AND SIGNING -----------

    std::cout << "\n----- Testing Form Creation and Signing -----" << std::endl;

    ShrubberyCreationForm shrubberyForm("home");
    RobotomyRequestForm robotomyForm("Alice");
    PresidentialPardonForm pardonForm("Bob");
    Bureaucrat f("Frank", 50);

    try 
    {
        std::cout << "Attempting to sign Shrubbery Creation Form" << std::endl;
        f.signForm(shrubberyForm);
        std::cout << "Shrubbery form signed: " << shrubberyForm << std::endl;
    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }
    try 
    {
        std::cout << "Attempting to sign Robotomy Request Form" << std::endl;
        f.signForm(robotomyForm);
        std::cout << "Robotomy form signed: " << robotomyForm << std::endl;
    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }
    try 
    {
        std::cout << "Attempting to sign Presidential Pardon Form" << std::endl;
        f.signForm(pardonForm);
        std::cout << "Presidential Pardon form signed: " << pardonForm << std::endl;
    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }

    // ----------- TESTING FORM EXECUTION -----------

    std::cout << "\n----- Testing Form Execution -----" << std::endl;

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
    //shrubberyForm.beSigned(g);
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
    //robotomyForm.beSigned(g);
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
    //pardonForm.beSigned(g);
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
    std::cout << "\n----- All Tests Completed -----" << std::endl;
    return 0;
}
