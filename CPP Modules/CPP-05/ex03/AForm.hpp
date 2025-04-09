/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:51:52 by sde-carv          #+#    #+#             */
/*   Updated: 2025/03/24 13:51:54 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool is_signed;
        const int sign_grade;
        const int execute_grade;

    public:
        AForm(const std::string &name, int sign, int execute);
        virtual ~AForm();
        AForm(const AForm &copy);
        AForm &operator=(const AForm &copy);

        void beSigned(const Bureaucrat &Bureaucrat);
        std::string getName() const;
        bool isSigned() const;
        int getSignGrade() const;
        int getExecuteGrade() const;
        void checkGradeAForm();
        virtual void execute(Bureaucrat const &executor) const = 0;
        static AForm* CreateForm(const std::string &target);
        
        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const AForm &AForm);

#endif
