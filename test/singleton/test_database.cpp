#include "singleton/database.hpp"

int main()
{
    std::vector<std::string> cap = {"Maranhão", "Belo Horizonte"};

    for (const auto& c : cap)
    {
        auto pop = SingletonDatabase::get().get_population(c);
        std::cout << "Capital: " << c << " População: " << pop << '\n';
    }

    return 0;
}