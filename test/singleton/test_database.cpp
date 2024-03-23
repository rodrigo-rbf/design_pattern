#include "singleton/database.hpp"

int main()
{
    std::vector<std::string> cap = {"Maranhão", "Minas Gerais"};

    for (const auto& c : cap)
    {
        auto pop = SingletonDatabase::get().get_population(c);
        std::cout << "Capital: " << c << " Population: " << pop << '\n';
    }

    SingletonRecordFinder sfr;
    std::cout << "Total population: " << sfr.totalpopulation(cap) << '\n';

    return 0;
}