#pragma once
#include <string>
//#include "builder/person_builder.hpp"

class Person_address_builder : public Person_builder_base
{
    private:
        typedef Person_address_builder Self;
  
    public:
        explicit Person_address_builder(Person& person)
        : Person_builder_base{person}
        {}

        Self& at(std::string street_address)
        {
            person.street_address = street_address;
            return *this;
        }

        Self& with_postcode(std::string post_code)
        {
            person.post_code = post_code;
            return *this;
        }

        Self& in(std::string city)
        {
            person.city = city;
            return *this;
        }
    
};