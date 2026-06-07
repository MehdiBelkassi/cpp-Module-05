#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form() : name("Mehdi"), is_signed(false), grade_to_sign(150), grade_to_execute(150)
{
    std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(std::string _name, int grade_to_sign, int grade_to_execute)
    :name(_name), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
    {
        std::cout << "Form constructor called" << std::endl;
        if (grade_to_sign > 150 || grade_to_execute > 150)
		    throw Form::GradeTooLowException();
	    else if (grade_to_sign < 1 || grade_to_execute < 1)
		    throw Form::GradeTooHighException();
    }

Form::Form(Form const &other)
    :name(other.name), is_signed(other.is_signed), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute)
    {
        std::cout << "Form copy constructor called" << std::endl;
    }

Form& Form::operator=(Form const &other)
{
    std::cout << "Form copy assigment operator called" << std::endl;
    if (this != &other)
        is_signed = other.is_signed;
    return (*this);
}

Form::~Form()
{
    std::cout << "Form Destructor called" << std::endl;
}

std::string Form::getName() const
{
    return name;
}

bool Form::get_is_signed() const
{
    return is_signed;
}

int Form::get_grade_to_execute() const
{
    return grade_to_execute;
}

int Form::get_grade_to_sign() const
{
    return grade_to_sign;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() < 1)
        throw GradeTooHighException();
    else if (bureaucrat.getGrade() > 150)
        throw GradeTooLowException();

    if (is_signed)
        throw FormAlreadySignedException();

    is_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "the grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "the grade is too Low";
}

const char* Form::FormAlreadySignedException::what() const throw()
{
    return "the form is already signed";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "The form's name is " << form.getName() << " and the grade to sign is " << form.get_grade_to_sign()
        << " and the grade to execute is " << form.get_grade_to_execute() << " and the status of signature is " <<
        form.get_is_signed() << " .\n";
    
    return os;
}