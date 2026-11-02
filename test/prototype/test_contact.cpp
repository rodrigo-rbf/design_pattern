#include "prototype/contact.hpp"


int main()
{

    Contact john{"John Doe", Address{"Rua Teodorico", "Rio de Janeiro", 318}};
    Contact aline = john;
    aline.name = "Aline Britto";
    aline.address.suite = 320;

    std::cout << '\n' << john << std::endl << aline << '\n' << std::endl;;


    return 0;
}