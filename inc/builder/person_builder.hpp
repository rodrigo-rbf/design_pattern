#pragma once
#include "builder/person.hpp"

class Person_address_builder;
class Person_job_builder;

class Person_builder_base
{
    public:
        operator Person() const { return std::move(person);}

        //builder facets
        Person_address_builder lives() const;
        Person_job_builder works() const;

    protected:
        Person& person;
        explicit Person_builder_base(Person& person) : person{person} {}
};

class Person_builder : public Person_builder_base
{
    public:
        Person_builder() : Person_builder_base(p)
        {}
    private:
        Person p;
};