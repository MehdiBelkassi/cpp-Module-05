#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>
#include <iostream>

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool is_signed;
        const int grade_to_sign;
        const int grade_to_execute;
    public:
        AForm();
        AForm(std::string _name, int _grade_to_sign, int _grade_to_execute);
        AForm(AForm const &other);
        AForm& operator=(AForm const &other);
        virtual ~AForm(); 

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

        class FormIsnotSignedException : public std::exception
	    {
		    const char* what() const throw();
	    };
        virtual void execute(Bureaucrat const & executor) const = 0; //to be tested, u know why
};

std::ostream &operator<<(std::ostream &ostream, const AForm &Aform);





#endif
