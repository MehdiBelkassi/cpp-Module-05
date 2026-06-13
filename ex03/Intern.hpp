#ifndef INTERN_HPP
# define INTERN_HPP



#include "Bureaucrat.hpp"
#include "AForm.hpp"




class Intern
{
    public:
        Intern();
        Intern(std::string Force_Orthodox_Canonical_Form);
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        AForm* makeForm(std::string form, std::string target);
};

#endif