#include "Bureaucrat.hpp"




int main()
{

    try
    {
        Bureaucrat solder1("mehdi", 2147483647);
        solder1.decreaseGrade();
        std::cout << solder1.getGrade() << std::endl;

    }
    catch(std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }
}
