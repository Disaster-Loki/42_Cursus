/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:52:01 by sde-carv          #+#    #+#             */
/*   Updated: 2025/03/24 13:52:02 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string &name, int sign_grade, int execute_grade) 
    : name(name), is_signed(false), sign_grade(sign_grade), execute_grade(execute_grade)
{
    checkGradeAForm();
    std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(const AForm &copy) 
    : name(copy.name), is_signed(copy.is_signed), sign_grade(copy.sign_grade), execute_grade(copy.execute_grade)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &copy) {
    if (this != &copy) {
        this->is_signed = copy.is_signed;
        std::cout << this->name << " AForm copy assign_gradement operator called" << std::endl;
    }
    return *this;
}

AForm::~AForm() 
{
    std::cout << "AForm destructor called" << std::endl;
}

std::string AForm::getName() const { return name; }
bool AForm::isSigned() const { return is_signed; }
int AForm::getSignGrade() const { return sign_grade; }
int AForm::getExecuteGrade() const { return execute_grade; }

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->sign_grade)
        throw AForm::GradeTooLowException();
    this->is_signed = true;
}

void AForm::checkGradeAForm(){
    if (this->sign_grade < 1 || this->execute_grade < 1)
        throw GradeTooHighException();
    if (this->sign_grade > 150 || this->execute_grade > 150)
        throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "F-Error: Grade Too High";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "F-Error: Grade Too Low";
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm) {
    out << "AForm: " << AForm.getName() 
        << ", sign_graded: " << (AForm.isSigned() ? "Yes" : "No")
        << ", sign_grade Grade: " << AForm.getSignGrade()
        << ", execute_grade Grade: " << AForm.getExecuteGrade();
    return out;
}