#ifndef _SINGLETON_DATABASE_HPP_
#define _SINGLETON_DATABASE_HPP_

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>

#include <boost/lexical_cast.hpp>

class Database
{
    public:
        virtual size_t get_population(const std::string capital_name) = 0;
};

class SingletonDatabase : public Database
{
    public:
        SingletonDatabase(SingletonDatabase const&) = delete;
        void operator = (SingletonDatabase const&) = delete;

        static SingletonDatabase& get()
        {
            static SingletonDatabase db;
            return db;
        }

        size_t get_population(const std::string capital)
        {
            return capitals[capital];
        }
    
    private:
        SingletonDatabase()
        {
            std::string path = std::filesystem::current_path();
            std::string file_name = "capitaisbrasil.txt";
            std::cout << "Initializing database\n";
            std::ifstream ifs(path + "/test/" + file_name);
            std::string s, s2;

            while(getline(ifs, s))
            {
                size_t pop;
                getline(ifs, s2);
                try {
                pop = static_cast<size_t>(std::stoul(s2));
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Erro - invalid_argument: " << e.what() << std::endl;
                } catch (const std::out_of_range& e) {
                    std::cerr << "Erro - out of range: " << e.what() << std::endl;
                }
            
                capitals[s] = pop;  
            }
        }

        std::map<std::string, int> capitals;
};

struct SingletonRecordFinder
{
    SingletonRecordFinder(){};
    size_t totalpopulation(std::vector<std::string> names)
    {
        size_t result{0};
        for (const auto& name : names)
        {
            result += SingletonDatabase::get().get_population(name);
        }
        return result;
    }
};



#endif