// #include <vector>
// #include <string>
// #include <gtest/gtest.h>
// using namespace std;

// namespace FactoryExercise {

// struct Person
// {
//   int id;
//   string name;
// };

// class PersonFactory
// {
//   int id{ 0 };
// public:
//   Person create_person(const string& name)
//   {
//     return { id++, name };
//   }
// };

// #include "gtest/gtest.h"

// //#include "helpers/iohelper.h"

// //#include "exercise.cpp"


// namespace
// {
//   class Evaluate : public testing::Test
//   {
//   };

//   TEST_F(Evaluate, SimplePersonTest)
//   {
//     PersonFactory pf;

//     auto p1 = pf.create_person("Chris");
//     ASSERT_EQ("Chris", p1.name);

//     auto p2 = pf.create_person("Sarah");
//     ASSERT_EQ(1, p2.id) << "Expected the second created person's id to be = 1";
//   }
// } // namespace

// }

// int main(int ac, char* av[])
// {
//   testing::InitGoogleTest(&ac, av);
//   return RUN_ALL_TESTS();
// }

/////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <memory>
#include <thread>
#include <mutex>

using namespace std;

struct Person
{
  int id;
  string name;
};

template <typename T>
class PersonSingleton
{
  public:
    static PersonSingleton& create_instance()
    {
        std::lock_guard<std::mutex> lock(m_mtx);
        static  PersonSingleton instance;
        return instance;
    }

    void set_person(std::string name)
    {
        count = ++count;
        person.name = name;
        person.id = count-1;
    }

    Person get_person()
    {
        return person;
    }

  private:
    PersonSingleton(){}
    ~PersonSingleton(){}
    int count = 0;
    Person person;
    static std::mutex m_mtx;
        
};
template <typename T>
std::mutex PersonSingleton<T>::m_mtx;


class PersonFactory //: public PersonSingleton<Person>
{
public:

  PersonFactory(){}
  ~PersonFactory(){}
  
  Person create_person(const string& name)
  {
    auto& person_sgt = PersonSingleton<Person>::create_instance();
    person_sgt.set_person(name);

    return person_sgt.get_person();
  }     
 
};

int main()
{
    auto rbf = PersonFactory().create_person("Rodrigo");
    auto amb = PersonFactory().create_person("Aline");
    auto lmb = PersonFactory().create_person("Lorenzo");
    auto fmb = PersonFactory().create_person("Florença");


    std::cout << rbf.id << ": " << rbf.name << '\n';
    std::cout << amb.id << ": " << amb.name << '\n';
    std::cout << lmb.id << ": " << lmb.name << '\n';
    std::cout << fmb.id << ": " << fmb.name << '\n';



    return 0;
}

