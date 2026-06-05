#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form() : name(name), is_signed(false), grade_to_sign(150), grade_to_execute(150)
{
    std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(std::string _name, int grade_to_sign, int grade_to_execute)
    :name(_name), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
    {
        std::cout << "Form constructor called" << std::endl;
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

