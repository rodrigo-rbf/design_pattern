#include<iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

// A. High-level modules should not depend on low-level modules.
//    Both should depend on abstractions.
// B. Abstractions should not depend on details. 
//    Details should depend on abstractions.

enum class Relationship{parent, child, sibling};

struct Person{
    string name;
};

struct RelationshipBrowser{
    virtual vector<Person> find_all_children_of(const string& name) = 0;
};

struct Relationships : RelationshipBrowser{
    vector<tuple<Person, Relationship, Person>> relations;

    void add_parent_and_child(const Person& parent, const Person& child)
    {
        relations.push_back({parent, Relationship::parent, child});
        relations.push_back({child, Relationship::child, parent});
    }

    vector<Person> find_all_children_of(const string& name) override
    {
        vector<Person> result;
        for (auto& r : relations)
        {
            if(get<0>(r).name == name && get<1>(r) == Relationship::parent)
                result.push_back(get<2>(r));
        }
        return result;
    }
};

struct Research{
    Research(RelationshipBrowser& browser)
    {
        for (auto& child : browser.find_all_children_of("John"))
            cout << "John has a child called " << child.name << endl;
        
    }
};

int main()
{
  Person parent{"John"};
  Person child1{"Chris"};
  Person child2{"Matt"};

  Relationships relationships;
  relationships.add_parent_and_child(parent, child1);
  relationships.add_parent_and_child(parent, child2);

  Research research(relationships);

  return 0;
}