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
#include <iostream>
#include <exception>

int main() 
{
    // ----------- TESTING BUREAUCRAT CLASS -----------
    std::cout << "\n----- Testing Constructor with Invalid Grades -----" << std::endl;
    try 
    {
        Bureaucrat b("Alice", 151);  // Exceção esperada: GradeTooLowException
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try 
    {
        Bureaucrat b("Bob", 0);  // Exceção esperada: GradeTooHighException
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n----- Testing Valid Bureaucrat Creation -----" << std::endl;
    Bureaucrat c("Charlie", 42);  // Nenhuma exceção
    std::cout << c << std::endl;

    std::cout << "\n----- Testing Incrementing and Decrementing Grades -----" << std::endl;
    try 
    {
        Bureaucrat d("David", 2);
        std::cout << d << std::endl;
        d.incrementGrade();  // Deve funcionar
        std::cout << "After increment: " << d << std::endl;
        d.incrementGrade();  // Exceção esperada: GradeTooHighException
    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }

    try 
    {
        Bureaucrat e("Eve", 149);
        std::cout << e << std::endl;
        e.decrementGrade();  // Deve funcionar
        std::cout << "After decrement: " << e << std::endl;
        e.decrementGrade();  // Exceção esperada: GradeTooLowException
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

    Bureaucrat f("Frank", 50);  // Grau válido para assinar

    try 
    {
        std::cout << "Attempting to sign Shrubbery Creation Form" << std::endl;
        shrubberyForm.beSigned(f);  // Deve funcionar, já que Frank tem grau suficiente para assinar
        std::cout << "Shrubbery form signed: " << shrubberyForm << std::endl;
    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }

    try 
    {
        std::cout << "Attempting to sign Robotomy Request Form" << std::endl;
        robotomyForm.beSigned(f);  // Deve funcionar
        std::cout << "Robotomy form signed: " << robotomyForm << std::endl;
    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }

    try 
    {
        std::cout << "Attempting to sign Presidential Pardon Form" << std::endl;
        pardonForm.beSigned(f);  // Deve falhar, pois Frank tem grau 50, mas é necessário grau 25 para assinar
        std::cout << "Presidential Pardon form signed: " << pardonForm << std::endl;
    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }

    // ----------- TESTING FORM EXECUTION -----------

    std::cout << "\n----- Testing Form Execution -----" << std::endl;

    Bureaucrat g("George", 5);  // Grau baixo o suficiente para executar qualquer um dos formulários

    try 
    {
        std::cout << "Attempting to execute Shrubbery Creation Form" << std::endl;
        g.executeForm(shrubberyForm);  // Não deve funcionar, pois o formulário não foi assinado
    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }

    // Assinando o formulário para permitir execução
    shrubberyForm.beSigned(g);

    try 
    {
        std::cout << "Attempting to execute Shrubbery Creation Form after signing" << std::endl;
        g.executeForm(shrubberyForm);  // Deve funcionar
    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }

    try 
    {
        std::cout << "Attempting to execute Robotomy Request Form" << std::endl;
        g.executeForm(robotomyForm);  // Não deve funcionar, pois o formulário não foi assinado
    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }

    // Assinando o formulário para permitir execução
    robotomyForm.beSigned(g);

    try 
    {
        std::cout << "Attempting to execute Robotomy Request Form after signing" << std::endl;
        g.executeForm(robotomyForm);  // Deve funcionar e simular a robotização
    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }

    try 
    {
        std::cout << "Attempting to execute Presidential Pardon Form" << std::endl;
        g.executeForm(pardonForm);  // Não deve funcionar, pois o formulário não foi assinado
    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }

    // Assinando o formulário para permitir execução
    pardonForm.beSigned(g);

    try 
    {
        std::cout << "Attempting to execute Presidential Pardon Form after signing" << std::endl;
        g.executeForm(pardonForm);  // Deve funcionar e exibir a mensagem de perdão
    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n----- All Tests Completed -----" << std::endl;

    return 0;
}
