#include "journal.hpp"

using namespace std;

void Journal::add(const string& entry)
{
    static int count = 1;
    entries.push_back(boost::lexical_cast<string>(count++) + ": " + entry);
}

void Journal::save(const string& filename)
{
    ofstream ofs(filename);
    for (auto& s : entries)
        ofs << s << endl;
}

void PersistenceManager::save(const Journal& j, const string& filename)
{
    ofstream ofs(filename);
    for (auto& s : j.entries)
        ofs << s << endl;
}