/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:52:01 by sde-carv          #+#    #+#             */
/*   Updated: 2025/03/24 13:52:02 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string &name, int sign, int execute) 
    : name(name), is_signed(false), sign(sign), execute(execute)
{
    checkGradeForm();
    std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form &copy) 
    : name(copy.name), is_signed(copy.is_signed), sign(copy.sign), execute(copy.execute)
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &copy) {
    if (this != &copy) {
        this->is_signed = copy.is_signed;
        std::cout << this->name << " Form copy assignment operator called" << std::endl;
    }
    return *this;
}

Form::~Form() 
{
    std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const { return name; }
bool Form::isSigned() const { return is_signed; }
int Form::getSignGrade() const { return sign; }
int Form::getExecuteGrade() const { return execute; }

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->sign)
        throw Form::GradeTooLowException();
    this->is_signed = true;
}

void Form::checkGradeForm(){
    if (this->sign < 1 || this->execute < 1)
        throw GradeTooHighException();
    if (this->sign > 150 || this->execute > 150)
        throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw() {
    return "F-Error: Grade Too High";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "F-Error: Grade Too Low";
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
    out << "Form: " << form.getName() 
        << ", Signed: " << (form.isSigned() ? "Yes" : "No")
        << ", Sign Grade: " << form.getSignGrade()
        << ", Execute Grade: " << form.getExecuteGrade();
    return out;
}