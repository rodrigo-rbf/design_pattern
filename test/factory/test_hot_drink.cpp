#include <iostream>
#include <memory>

#include "factory/hot_drink_factory.hpp"
#include "factory/drink_factory.hpp"



int main()
{
    // DrinkFactory df, df2;
    // df

    // df.make_drink("tea", 250);

    // df2.make_drink("tea", 300);

    DrinkWithVolumeFactory().make_drink(Drink::coffee, 55);
    DrinkWithVolumeFactory().make_drink(Drink::coffee, 100);
    DrinkWithVolumeFactory().make_drink(Drink::tea, 210);

    DrinkVolumeFactory(Drink::coffee, 60).make();
    DrinkVolumeFactory(Drink::tea, 70).make();
    // DrinkVolumeFactory().make_drink("coffee", 101);

   
  
    return 0;
}