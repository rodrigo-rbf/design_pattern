#ifndef _DRINK_FACTORY_HPP_
#define _DRINK_FACTORY_HPP_

#include <map>
#include <functional>

#include "factory/hot_drink.hpp"
#include "factory/hot_drink_factory.hpp"

class DrinkFactory
{
    public:
        DrinkFactory()
        {
            hot_factories["tea"] = std::make_unique<TeaFactory>();
            hot_factories["coffee"] = std::make_unique<CoffeeFactory>();
        }
    
    public:
        std::unique_ptr<HotDrink> make_drink(const std::string& name, int volume)
        {
            auto drink = hot_factories[name]->make();
            drink->prepare(volume);
            return drink;
        }

    private:
        std::map<std::string, std::unique_ptr<HotDrinkFactory>> hot_factories;
        
};

class DrinkWithVolumeFactory
{
    public:
        DrinkWithVolumeFactory()
        {
            factories["tea"] = std::make_unique<TeaFactory>();
            factories["coffee"] = std::make_unique<CoffeeFactory>();
        }

        std::unique_ptr<HotDrink> make_drink(Drink hot_drink, int volume)
        {
            auto drink = std::unique_ptr<HotDrink>(nullptr);
           
            switch (hot_drink)
            {
            case Drink::coffee :
                drink = factories[drink_str[0]]->make();
                drink->prepare(volume);
                return drink;
                break;
            
            case Drink::tea :
                drink = factories[drink_str[1]]->make();
                drink->prepare(volume);
                return drink;
                break;
            
            default:
                break;
            }

            return std::unique_ptr<HotDrink>(nullptr);
        }

    private:
        std::map<std::string, std::unique_ptr<HotDrinkFactory>> factories;
        
};

class DrinkVolumeFactory : public DrinkFactory {
public:
    DrinkVolumeFactory(){}
    DrinkVolumeFactory(Drink hot_drink, int volume) : hot_drink(hot_drink), volume(volume) {}

    std::unique_ptr<HotDrink> make() {
        switch (hot_drink) {
            case Drink::coffee:
                return make_drink("coffee", volume);
            case Drink::tea:
                return make_drink("tea", volume);
            default:
                return nullptr;
        }
    }

private:
    Drink hot_drink;
    int volume;
   
};


#endif

