/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 09:56:50 by sde-carv          #+#    #+#             */
/*   Updated: 2025/03/17 09:56:52 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade) {
    checkGrade();
    std::cout << this->name << " Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name), grade(copy.grade) {
    std::cout << this->name << " Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
    if (this != &copy) {
        this->grade = copy.grade;
        std::cout << this->name << " Bureaucrat copy assignment operator called" << std::endl;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << this->name << " Bureaucrat destructor called" << std::endl;
}

const std::string &Bureaucrat::getName() const { return this->name; }
int Bureaucrat::getGrade() const { return this->grade; }

void Bureaucrat::checkGrade()
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

void Bureaucrat::incrementGrade() {
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade() {
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "B-Error: Grade Too High";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "B-Error: Grade Too Low";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}

void Bureaucrat::signForm(AForm &form) {
    try
    {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << this->name << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->name << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}