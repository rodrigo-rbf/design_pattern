#include <iostream>
#include <string>
#include <ostream>
#include <vector>
#include <memory>

using namespace std;

class CodeBuilder
{
  public:
    CodeBuilder(const string& class_name) : class_name(class_name)
    {}

    CodeBuilder& add_field(const string& name, const string& type)
    {
      attributes.emplace_back(make_pair(name,type));
      return *this;
    }

    friend ostream& operator<<(ostream& os, const CodeBuilder& obj)
    {
      os << "class " << obj.class_name << '\n' << "{\n";
      for( const auto& e : obj.attributes)  
        os << "  " << e.second << " " << e.first << ";\n";
      os << "};\n";
      return os;
    }

  private:
    string class_name;
    std::vector<std::pair<std::string, std::string>> attributes;
};


int main(){
  auto cb = CodeBuilder("Person").add_field("name", "string").add_field("age", "int");
  cout << cb;

  return 0;
}

/*
You are asked to implement the Builder design pattern for rendering simple chunks of code.

Sample use of the builder you are asked to create:

    auto cb = CodeBuilder{"Person"}.add_field("name", "string").add_field("age", "int");
    cout << cb;

The expected output of the above code is:

    class Person
    {
      string name;
      int age;
    };

Please observe the same placement of curly braces and use two-space indentation.
*/