#include "builder/person.hpp"
#include "builder/person_builder.hpp"

Person_builder Person::create()
{
  return Person_builder();
}
