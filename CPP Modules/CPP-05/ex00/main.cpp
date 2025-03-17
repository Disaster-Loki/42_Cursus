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

    std::cout << "\n----- All Tests Completed -----" << std::endl;
    
    return 0;
}


