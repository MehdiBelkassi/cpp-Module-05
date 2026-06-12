
#ifndef SHRUBBERYCREATIONFROM_HPP
# define SHRUBBERYCREATIONFROM_HPP

#include "AForm.hpp"
#include <fstream>


class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm &other);
        ShrubberyCreationForm& operator=(ShrubberyCreationForm &other);
        ~ShrubberyCreationForm();

        void execute(Bureaucrat const & executor) const;
};

#endif
