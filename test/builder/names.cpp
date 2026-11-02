#include <iostream>
#include <vector>
#include <sstream>


class Names
{
    public:
        Names(){}
        Names(std::string name) :
        name(name)
        {}

        void add(std::string name){
            names.push_back(name);
        }

        std::vector<std::string> get(){
            return names;
        }

        std::string str(){
            std::ostringstream oss;
            std::string i(" ");
            for(auto const& n : names)
            {
                oss << n << i;
            }
            return oss.str();
        }

    private:
        std::vector<std::string> names;
        std::string name;      
};

class Full_name
{
    public:
        Full_name(){}
        Full_name(std::string first_name){
            full_names.add(first_name);
        }

        Full_name& add_name(std::string name){
            //Names e{ name };
            //full_names.names.emplace_back(e);
            full_names.add(name);
            return *this;
        }

        void add(std::string name){
            full_names.add(name);
        }

        std::string str(){
            return full_names.str();
        }

        operator Names() const { return full_names; }

    private:
        Names full_names;
};

int main()
{ 
    Full_name full1;
    Full_name full2;
    Full_name full3;
    
    full1.add_name("Rodrigo de").add_name("Britto").add_name("Florencio");
    std::cout << full1.str() << "\n";

    std::cout << full2.add_name("Aline").add_name("Muller").add_name("de").add_name("Britto").str() << '\n';

    full3.add("Lorenzo");
    full3.add("Muller");
    full3.add("de");
    full3.add("Britto");
    std::cout<<full3.str() << '\n';

    return 0;
}