#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("None")
{
    std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other) : AForm("PresidentialPardonForm", 25, 5), target(other.target)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm &other)
{
    std::cout << "PresidentialPardonForm copy assigment operator called" << std::endl;
    if (this != &other)
        target = other.target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

const char* PresidentialPardonForm::GradeTooHighException::what() const throw()
{
    return "Unfortunatly, The Grade has is too High and he has not been pardoned by Zaphod Beeblebrox";
}

const char* PresidentialPardonForm::GradeTooLowException::what() const throw()
{
    return "Unfortunatly, The Grade has is too Low and he has not been pardoned by Zaphod Beeblebrox";
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!this->get_is_signed())
        throw AForm::FormIsnotSignedException();

    if (executor.getGrade() > this->get_grade_to_sign() )
        throw PresidentialPardonForm::GradeTooLowException();

    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
