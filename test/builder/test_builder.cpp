
#include "builder/builder.hpp"

using namespace std;

int main(){

    HtmlBuilder builder{ "ul" };
    builder.add_child("li", "hello").add_child("li", "world");
    cout << builder.str() << endl;

    HtmlBuilder builder2{ "ul" };
    builder2.add_child_2("li", "hello")->add_child_2("li", "world");
    cout << builder2.str() << endl;

    getchar();
    return 0;

}