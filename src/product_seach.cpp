#include "product_seach.hpp"

std::vector<Product*> ProductFilter::by_color(std::vector<Product*> items, Color color)
{
    std::vector<Product*> result;
    for (auto& i : items)
        if(i->color == color)
            result.push_back(i);
    return result;
}

std::vector<Product*> ProductFilter::by_size(std::vector<Product*> items, Size size)
{
    std::vector<Product*> result;
    for (auto& i : items)
        if(i->size == size)
            result.push_back(i);
    return result;
}

std::vector<Product*> ProductFilter::by_size_and_color(std::vector<Product*> items, Size size, Color color){
    std::vector<Product*> result;
    for (auto& i : items)
        if(i->size == size && i->color == color)
            result.push_back(i);
    return result;
} 