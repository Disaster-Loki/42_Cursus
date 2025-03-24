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
#include "Form.hpp"

int main() 
{
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

    std::cout << "\n----- Testing Copy Constructor & Assignment Operator -----" << std::endl;
    Bureaucrat f("Frank", 50);
    Bureaucrat g(f);
    std::cout << "Copied Bureaucrat: " << g << std::endl;

    Bureaucrat h("Henry", 100);
    std::cout << "Before assignment: " << h << std::endl;
    h = g;
    std::cout << "After assignment: " << h << std::endl;

    // ----------- TESTING FORM CLASS -----------
    std::cout << "\n----- Testing Form Creation -----" << std::endl;
    try 
    {
        Form form1("Tax Form", 50, 25);
        std::cout << form1 << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }

    try 
    {
        Form form2("Invalid Form", 0, 25);
        std::cout << form2 << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }

    try 
    {
        Form form3("Invalid Form", 160, 25);
        std::cout << form3 << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n----- Testing Form Signing -----" << std::endl;
    Bureaucrat boss("Boss", 10);
    Form contract("Employment Contract", 20, 5);

    std::cout << boss << std::endl;
    std::cout << contract << std::endl;

    try 
    {
        contract.beSigned(boss);
        std::cout << "After signing: " << contract << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cout << boss.getName() << " couldn't sign " << contract.getName() << " because " << e.what() << std::endl;
    }

    Bureaucrat intern("Intern", 100);
    Form nda("NDA", 50, 30);

    std::cout << intern << std::endl;
    std::cout << nda << std::endl;

    try 
    {
        nda.beSigned(intern);
        std::cout << "After signing: " << nda << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cout << intern.getName() << " couldn't sign " << nda.getName() << " because " << e.what() << std::endl;
    }

    std::cout << "\n----- Testing Bureaucrat's signForm() -----" << std::endl;
    Bureaucrat manager("Manager", 30);
    Form budget("Budget Approval", 40, 20);

    std::cout << manager << std::endl;
    std::cout << budget << std::endl;

    manager.signForm(budget);
    std::cout << "After signing attempt: " << budget << std::endl;

    Bureaucrat junior("Junior Staff", 60);
    Form report("Project Report", 50, 30);

    std::cout << junior << std::endl;
    std::cout << report << std::endl;

    junior.signForm(report);
    std::cout << "After signing attempt: " << report << std::endl;

    std::cout << "\n----- All Tests Completed -----" << std::endl;
    
    return 0;
}
