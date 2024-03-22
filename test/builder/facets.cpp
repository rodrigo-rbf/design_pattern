#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

#include "builder/person.hpp"
#include "builder/person_builder.hpp"
#include "builder/person_address_builder.hpp"
#include "builder/person_job_builder.hpp"

int main()
{
  Person p = Person::create()
    .lives().at("123 London Road").with_postcode("SW1 1GB").in("London")
    .works().at("PragmaSoft").as_a("Consultant").earning(10e6);

  cout << p << endl;
  getchar();
  return 0;
}
