#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "grade is too low";
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

Bureaucrat::Bureaucrat(std::string _name, int _grade):name(_name), grade(_grade)
{
    if (_grade < 1)
    {
        throw GradeTooHighException();
    }
    else if (_grade > 150)
    {
        throw GradeTooLowException();
    }
}
