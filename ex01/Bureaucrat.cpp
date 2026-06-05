#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("none"), grade(1)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string _name, int _grade):name(_name), grade(_grade)
{
     
    if (_grade < 1)
        throw GradeTooHighException();
    else if (_grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : name(other.name),grade(other.grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &other)
{
    std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    if (this != &other)
        grade = other.grade;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat Destructor called" << std::endl;
}

const std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::decreaseGrade()
{
    if (grade == 150)
        throw GradeTooLowException();
    grade++;
}

void Bureaucrat::increaseGrade()
{
    if (grade == 1)
        throw GradeTooHighException();
    grade--;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "grade is too low";
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return os;
}
