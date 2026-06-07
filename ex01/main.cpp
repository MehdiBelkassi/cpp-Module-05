











#include "Form.hpp"
#include "Bureaucrat.hpp"


int main()
{
    try
    {
        Form a = Form("3a9d zawaj", 14, 45);

        Bureaucrat solder1 = Bureaucrat("mehdi", 20);

        solder1.signForm(a);
        // std::cout << a;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}