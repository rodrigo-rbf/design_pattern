#ifndef __BUILDER_HPP__
#define __BUILDER_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
using namespace std;

class HtmlBuilder;

class HtmlElement{
    public:
        HtmlElement(){};
        HtmlElement(const string& name, const string& text)
        : name(name),
        text(text)
        {}

        string str(int indent) const;
        //static unique_ptr<HtmlBuilder> build(string root_name);
        static unique_ptr<HtmlElement> build(const string& root_name);
    
        string name;
        string text;
        vector<HtmlElement> elements;
        const size_t indent_size = 2;
    
};

class HtmlBuilder
{
    public:
        HtmlBuilder(string root_name)
        {
        root.name = root_name;
        }

        // void to start with
        HtmlBuilder& add_child(string child_name, string child_text);
    
        // pointer based
        HtmlBuilder* add_child_2(string child_name, string child_text);
       
        string str();

        operator HtmlElement() const { return root; }
    
    private:
        HtmlElement root;
};



#endif