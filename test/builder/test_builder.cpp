
#include "builder/builder.hpp"

using namespace std;

int main(){

    html::HtmlBuilder builder{ "ul" };
    builder.add_child("li", "hello").add_child("li", "world").add_child("li", "space") ;
    cout << builder.str() << endl;

    html::HtmlBuilder builder2{ "ul" };
    builder2.add_child_2("li", "hello")->add_child_2("li", "world");
    cout << builder2.str() << endl;

    std::cout << html::P {html::IMG{"http://pokemon.com/pikachu.png"}} << std::endl;

    getchar();
    return 0;

}