#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm() : name("Mehdi"), is_signed(false), grade_to_sign(150), grade_to_execute(150)
{
    std::cout << "AForm Default constructor called" << std::endl;
}

AForm::AForm(std::string _name, int grade_to_sign, int grade_to_execute)
    :name(_name), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
    {
        std::cout << "AForm constructor called" << std::endl;
        if (grade_to_sign > 150 || grade_to_execute > 150)
		    throw AForm::GradeTooLowException();
	    else if (grade_to_sign < 1 || grade_to_execute < 1)
		    throw AForm::GradeTooHighException();
    }

AForm::AForm(AForm const &other)
    :name(other.name), is_signed(other.is_signed), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute)
    {
        std::cout << "AForm copy constructor called" << std::endl;
    }

AForm& AForm::operator=(AForm const &other)
{
    std::cout << "AForm copy assigment operator called" << std::endl;
    if (this != &other)
        is_signed = other.is_signed;
    return (*this);
}

AForm::~AForm()
{
    std::cout << "AForm Destructor called" << std::endl;
}

std::string AForm::getName() const
{
    return name;
}

bool AForm::get_is_signed() const
{
    return is_signed;
}

int AForm::get_grade_to_execute() const
{
    return grade_to_execute;
}

int AForm::get_grade_to_sign() const
{
    return grade_to_sign;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() < 1)
        throw GradeTooHighException();
    else if (bureaucrat.getGrade() > 150)
        throw GradeTooLowException();

    if (is_signed)
        throw AForm::FormAlreadySignedException();

    is_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "the grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "the grade is too Low";
}

const char* AForm::FormAlreadySignedException::what() const throw()
{
    return "the form is already signed";
}

const char* AForm::FormIsnotSignedException::what() const throw()
{
    return "the form is not signed";
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "The form's name is " << form.getName() << " and the grade to sign is " << form.get_grade_to_sign()
        << " and the grade to execute is " << form.get_grade_to_execute() << " and the status of signature is " <<
        form.get_is_signed() << " .\n";
    
    return os;
}

