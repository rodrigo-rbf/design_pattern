#ifndef __JOURNAL_HPP
#define __JOURNAL_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <boost/lexical_cast.hpp>

using namespace std;


struct Journal{
    string title;
    vector<string> entries;

    explicit Journal(const string& title) : title(title) {}

    void add(const string& entry);

    // persistence is a separete concern
    void save(const string& filename);
};

struct PersistenceManager
{
  static void save(const Journal& j, const string& filename);
  
};



#endif