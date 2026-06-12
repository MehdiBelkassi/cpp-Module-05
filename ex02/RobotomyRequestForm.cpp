#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 25, 5), target("None")
{
    std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 25, 5), target(target)
{
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other) : AForm("RobotomyRequestForm", 25, 5), target(other.target)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm &other)
{
    std::cout << "RobotomyRequestForm copy assigment operator called" << std::endl;
    if (this != &other)
        target = other.target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

// const char* RobotomyRequestForm::GradeTooHighException::what() const throw()
// {
//     return "The Grade is too High and the robotomy failed...";
// }

// const char* RobotomyRequestForm::GradeTooLowException::what() const throw()
// {
//     return "The Grade is too low and the robotomy failed...";
// }

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->get_is_signed())
        throw AForm::FormIsnotSignedException();

    if (executor.getGrade() > this->get_grade_to_sign() )
        throw AForm::GradeTooLowException();

    std::cout << target << " has been robotomized successfully 50% of the time" << std::endl;
}
