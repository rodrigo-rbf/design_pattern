#include "product_seach.hpp"

int main(){
    Product apple{"Aplle", Color::green, Size::small};
    Product tree{"Tree", Color::green, Size::large};
    Product house{"House", Color::blue, Size::large};
    Product car{"Car", Color::blue, Size::medium};

    std::vector<Product*> items = {&apple, &tree, &house, &car};

    ProductFilter pf;

    for (auto i : pf.by_color(items, Color::blue))
        std::cout << i->name << " is " << color_str[size_t(i->color)] << std::endl;
    
    for (auto i : pf.by_size(items, Size::large))
        std::cout << i->name << " is " << size_str[size_t(i->size)] << std::endl;
    
    for (auto i : pf.by_size_and_color(items, Size::large, Color::green))
        std::cout << i->name << " is " << size_str[size_t(i->size)] << " and color is " << color_str[size_t(i->color)] << std::endl;

    std::cout << "\n--------------------------\n";

    BetterFilter bf;
    ColorSpecification blue(Color::blue);
    for (auto& i : bf.filter(items, blue))
        std::cout << i->name << " is " << color_str[size_t(i->color)] << std::endl;
    
    SizeSpecification large(Size::large);
    ColorSpecification green(Color::green);
    AndSpecification<Product> green_and_large(green, large);

    for (auto& i : bf.filter(items, green_and_large))
        std::cout << i->name << " is " << color_str[size_t(i->color)] << std::endl;

}