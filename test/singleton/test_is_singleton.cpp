#include <functional>
#include <iostream>

#include "singleton/singleton.hpp"

using namespace std;

// Exemplo de uso
class MyClass
{
public:
    MyClass() {}
};

struct SingletonTester
{
    // template <typename T>
    // bool is_singleton(function<T*()> factory)
    // {
    //     T* instance1 = factory(); // Cria a primeira instância
    //     T* instance2 = factory(); // Cria a segunda instância

    //     // Compara os endereços de memória das instâncias
    //     return instance1 == instance2;
    // }

    // template <typename T, typename F>
    // bool is_singleton(F &factory)
    // {
    //     T* instance1 = factory(); // Cria a primeira instância
    //     T* instance2 = factory(); // Cria a segunda instância

    //     // Compara os endereços de memória das instâncias
    //     return instance1 == instance2;
    // }
};

int main()
{
    // SingletonTester tester;

   //auto& test_sgt = Singleton<MyClass>::create_instance();
    // Testa se MySingleton é um singleton
    // bool result = tester.is_singleton<Singleton<double>>(Singleton<double>::create_instance());
    // bool result = tester.is_singleton<MySingleton>(MySingleton::getInstance);
    
    // if (result)
    //     cout << "MySingleton é um singleton." << endl;
    // else
    //     cout << "MySingleton não é um singleton." << endl;

    // return 0;
}