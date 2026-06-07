#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <iostream>

class Bureaucrat;

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

        std::string getName() const;
        bool get_is_signed() const;
        int get_grade_to_execute() const;
        int get_grade_to_sign() const;

        void beSigned(const Bureaucrat &bureaucrat);

        class GradeTooHighException : public std::exception
        {
            const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            const char* what() const throw();
        };

        class FormAlreadySignedException : public std::exception
	    {
		const char* what() const throw();
	    };
};

std::ostream &operator<<(std::ostream &ostream, const Form &form);





#endif
