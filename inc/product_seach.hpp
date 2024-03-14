#ifndef __PRODUCT_SEACH_HPP
#define __PRODUCT_SEACH_HPP

// open closed principle

// open for extension, closed for modification


#include <iostream>
//#include <boost/lexical_cast>
#include <vector>
#include <string>
#include <array>

enum class Color{red, green, blue};
std::array<std::string, 3> color_str = {"Red", "Green", "Blue"};

enum class Size{small, medium, large};
std::array<std::string, 3> size_str = {"Small", "Medium", "Large"};

struct Product{
    std::string name;
    Color color;
    Size size;
};

struct ProductFilter{
    std::vector<Product*> by_color(std::vector<Product*> items, Color color);

    std::vector<Product*> by_size(std::vector<Product*> items, Size size);

    std::vector<Product*> by_size_and_color(std::vector<Product*> items, Size size, Color color);
};

template <typename T>
struct Specification{
    virtual bool is_satisfied(T* item) = 0;
};

template <typename T>
struct Filter{
    virtual std::vector<T*> filter(std::vector<T*> item, Specification<T>& spec) = 0;
};

struct BetterFilter : Filter<Product> {
    std::vector<Product*> filter(std::vector<Product*> items, Specification<Product>& spec) override
    {
        std::vector<Product*> result;
        for(auto& item : items)
            if(spec.is_satisfied(item))
                result.push_back(item);
        return result;
    }
};

struct ColorSpecification : Specification<Product>{
    Color color;
    ColorSpecification(Color color) : color(color){}
    bool is_satisfied(Product* item) override
    {
        return item->color == color;
    }
};

struct SizeSpecification : Specification<Product>{
    Size size;
    SizeSpecification(Size size) : size(size){}
    bool is_satisfied(Product* item) override
    {
        return item->size == size;
    }
};

template<typename T>
struct AndSpecification : Specification<T>{
    Specification<T>& first;
    Specification<T>& second;

    AndSpecification( Specification<T>& first, Specification<T>& second) : first(first), second(second){}

    bool is_satisfied(T* item) override{
        return first.is_satisfied(item) && second.is_satisfied(item);
    }
};


#endif