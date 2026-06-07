#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string _name, int _grade);
        Bureaucrat(Bureaucrat const &other);
        Bureaucrat& operator=(Bureaucrat const &other);
        ~Bureaucrat();

        const std::string getName() const;
        int getGrade() const;
        void decreaseGrade();
        void increaseGrade();
        void signForm(Form &form) const;

        class GradeTooHighException : public std::exception
        {
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat);

#endif
