#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 25, 5), target("None")
{
    std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 25, 5), target(target)
{
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other) : AForm("ShrubberyCreationForm", 25, 5), target(other.target)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm &other)
{
    std::cout << "ShrubberyCreationForm copy assigment operator called" << std::endl;
    if (this != &other)
        target = other.target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

// const char* ShrubberyCreationForm::GradeTooHighException::what() const throw()
// {
//     return "The Grade is too High";
// }

// const char* ShrubberyCreationForm::GradeTooLowException::what() const throw()
// {
//     return "The Grade is too  dddddLow";
// }

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!this->get_is_signed())
        throw AForm::FormIsnotSignedException();

    if (executor.getGrade() > this->get_grade_to_sign() )
        throw AForm::GradeTooLowException();

    std::ofstream file(target + "_shrubbery");
    file <<
    "          &&& &&  & &&\n"
    "      && &\\/&\\|& ()|/ @, &&\n"
    "      &\\/(/&/&||/& /_/)_&/_&\n"
    "   &() &\\/&|()|/&\\/ '%\" & ()\n"
    "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
    "&&   && & &| &| /& & % ()& /&&\n"
    " ()&_---()&\\&\\|&&-&&--%---()~\n"
    "     &&     \\|||\n"
    "             |||\n"
    "             |||\n"
    "             |||\n"
    "       , -=-~  .-^- _\n";
}





