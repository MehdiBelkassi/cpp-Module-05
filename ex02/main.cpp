#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main()
{
    try
    {
        Bureaucrat solder1("mehdi", 99); 

        ShrubberyCreationForm miaw("house");
        solder1.signForm(miaw);
        miaw.execute(solder1);

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

}