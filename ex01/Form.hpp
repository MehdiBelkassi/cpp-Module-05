#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string name;
        bool is_signed;
        const int grade_to_sign;
        const int grade_to_execute;
    public:
        Form();
        Form(std::string _name, int grade_to_sign, int grade_to_execute);
        Form(Form const &other);
        Form& operator=(Form const &other);
        ~Form();

        beSigned(Bureaucrat &other);
        class GradeTooHighException : public std::exception
        {
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            const char* what() const throw();
        };

};







#endif
