#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("None") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other) :  AForm("ShrubberyCreationForm", 145, 137), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm &other)
{
    if (this != &other)
        target = other.target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}


const char* ShrubberyCreationForm::GradeTooHighException::what() const throw()
{
    return "too high";
}

const char* ShrubberyCreationForm::GradeTooLowException::what() const throw()
{
    return "too low";
}

