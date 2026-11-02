
#include <iostream>
#include <string>

#include "factory/hot_drink.hpp"
#include "singleton/singleton.hpp"
#include "factory/drink_factory.hpp"
//#include "factory/hot_drink_factory.hpp"

class Config_manager
{
    public:
        Config_manager(){}
        Config_manager(std::string path) : path(path){}
        Config_manager(Config_manager& cfg_mng) : path(cfg_mng.get_path()){}

        void set_path(std::string path){ this->path = path;}
        std::string get_path(){ return path;}


    private:
        std::string path;
};

int main(){


    // auto cfg = Singleton<Config_manager>::get_content("/config/rbf/temp.cfg");
    // std::cout << "Path: " << cfg.get_path() << "\n";


    Singleton<Config_manager>::get_safe().create_instance();
    auto cfg1 = Singleton<Config_manager>::get_safe();
    cfg1.get_content().set_path("/config/novo_caminho/texto.txt");
    std::cout << "Path: " << cfg1.get_content().get_path() << "\n";

//    cfg1.set_path("rodrigo/britto/arquivo.teste");
//     std::cout << "Novo_Path: " << cfg1.get_path() << "\n";

//     // std::cout << "Novo_Path II: " << Singleton<Config_manager>::get_content().get_path() << "\n";

//     std::cout << "Novo_Path: " << cfg1.get_path() << "\n";
    

    return 0;
}