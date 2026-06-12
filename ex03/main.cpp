#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
    try
    {
        Bureaucrat solder1("mehdi", 150); 

        PresidentialPardonForm miaw("house");
        solder1.signForm(miaw);
        miaw.execute(solder1);

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

}