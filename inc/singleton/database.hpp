#ifndef _SINGLETON_DATABASE_HPP_
#define _SINGLETON_DATABASE_HPP_

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <tuple>
#include <boost/lexical_cast.hpp>

class SingletonDatabase
{
    public:
        SingletonDatabase(SingletonDatabase const&) = delete;
        void operator = (SingletonDatabase const&) = delete;

        static SingletonDatabase& get()
        {
            static SingletonDatabase db;
            return db;
        }
        

        size_t get_population(std::string capital)
        {
            return capitals[capital];
        }
    
    private:
        SingletonDatabase()
        {
            std::string path = "/home/rodrigo/Rodrigobf/StudyProgramming/designPattern/test";
            std::string file_name = "capitaisbrasil.txt";
            std::cout << "Initializing database\n";
            std::ifstream ifs(path + '/' + file_name);
            std::string s, s2;

            while(getline(ifs, s))
            {
                size_t pop;
                getline(ifs, s2);
                try {
                pop = static_cast<size_t>(std::stoul(s2));
                //std::cout << "Valor inteiro: " << pop << std::endl;
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

#endif