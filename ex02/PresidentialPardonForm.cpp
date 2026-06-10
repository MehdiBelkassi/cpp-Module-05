#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("None") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other) : AForm("PresidentialPardonForm", 25, 5), target(other.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm &other)
{
    if (this != &other)
        target = other.target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}


const char* PresidentialPardonForm::GradeTooHighException::what() const throw()
{
    return "too high";
}

const char* PresidentialPardonForm::GradeTooLowException::what() const throw()
{
    return "too low";
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!this->get_is_signed())
        throw AForm::FormIsnotSignedException();

    if (executor.getGrade() > this->get_grade_to_sign() )
        throw AForm::GradeTooLowException();

    std::cout << target << "has been pardoned by Zaphod Beeblebrox." << std::endl;
}
