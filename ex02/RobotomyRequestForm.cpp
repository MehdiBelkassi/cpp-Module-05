#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("None") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other) : AForm("RobotomyRequestForm", 72, 45), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm &other)
{
    if (this != &other)
        target = other.target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}


const char* RobotomyRequestForm::GradeTooHighException::what() const throw()
{
    return "too high";
}

const char* RobotomyRequestForm::GradeTooLowException::what() const throw()
{
    return "too low";
}
