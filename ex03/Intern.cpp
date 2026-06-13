
#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(std::string Force_Orthodox_Canonical_Form)
{
    (void)Force_Orthodox_Canonical_Form;
    std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
    (void)other;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
    std::cout << "Intern copy assigment operator called" << std::endl;
    (void)other;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern Destructor called" << std::endl;
}


AForm* Intern::makeForm(std::string form, std::string target)
{
    
}