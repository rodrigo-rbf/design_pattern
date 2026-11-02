#ifndef _FACTORY_HOT_DRINK_HPP_
#define _FACTORY_HOT_DRINK_HPP_

#include <iostream>
#include <memory>

enum class Drink{
    coffee,
    tea
};
std::array<std::string, 2> drink_str {"coffee", "tea"}; 

struct HotDrink
{
    virtual ~HotDrink() = default;
    virtual void prepare(int volume) = 0;
};

struct Coffee : HotDrink
{
    void prepare(int volume) override
    {
        std::cout << "Grind some beans, boil water, pour " << volume 
        << " ml, add cream, enjoy!\n";
    }
};

struct Tea : HotDrink
{
    void prepare(int volume) override
    {
        std::cout << "Take tea bag, boil water, pour " << volume 
        << " ml, add some lemon.\n";
    }
};






#endif