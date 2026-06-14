
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
AForm*  createPresidential( const std::string& target )
{
    return ( new PresidentialPardonForm( target ) );
}

AForm*  createRobotomy( const std::string& target )
{
    return ( new RobotomyRequestForm( target ) );
}

AForm*  createShrubbery( const std::string& target )
{
    return ( new ShrubberyCreationForm( target ) );
}

AForm* Intern::makeForm(std::string form, std::string target)
{
    std::string Forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

    AForm*  ( *FormFunctions[] )( const std::string& ) = { createPresidential, createRobotomy,createShrubbery};

    int i = 0;
    while (i < 3)
    {
        if (Forms[i] == form)
        {
            std::cout << "Intern creates " << Forms[i] << std::endl;
            return(FormFunctions[i](target));
        }
        i++;
    }
    std::cout << "The Form name given was not Found!" << std::endl;
    return ( NULL);
}