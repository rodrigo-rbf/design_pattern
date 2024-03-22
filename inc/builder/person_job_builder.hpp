#pragma once
#include "builder/person_builder.hpp"

class Person_job_builder : public Person_builder_base
{
  typedef Person_job_builder Self;
public:
  explicit Person_job_builder(Person& person)
  : Person_builder_base { person }
  {
  }

  Self& at(std::string company_name)
  {
    person.company_name = company_name;
    return *this;
  }

  Self& as_a(std::string position)
  {
    person.position = position;
    return *this;
  }

  Self& earning(int annual_income)
  {
    person.annual_income = annual_income;
    return *this;
  }
};