#pragma once
#include <string>
#include <iostream>

class Person_builder;

class Person
{
public:
    Person()
    {
        std::cout << "Person created    ";
    }
    ~Person()
    {
        std::cout << "Person destroyed    ";
    }

    static Person_builder create();

    Person(Person&& other)
    : street_address{move(other.street_address)},
      post_code{move(other.post_code)},
      city{move(other.city)},
      company_name{move(other.company_name)},
      position{move(other.position)},
      annual_income{other.annual_income}
    {}

    Person& operator=(Person&& other)
    {
        if (this == &other)
            return *this;
        street_address = move(other.street_address);
        post_code = move(other.post_code);
        city = move(other.city);
        company_name = move(other.company_name);
        position = move(other.position);
        annual_income = other.annual_income;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Person& obj)
    {
        return os
        << "street_address: " << obj.street_address
        << " post_code: " << obj.post_code
        << " city: " << obj.city
        << " company_name: " << obj.company_name
        << " position: " << obj.position
        << " annual_income: " << obj.annual_income;
    }


    friend class Person_builder;
    friend class Person_address_builder;
    friend class Person_job_builder;

private:
    // address
    std::string street_address, post_code, city;
    // employment
    std::string company_name, position;
    size_t annual_income{0};

};