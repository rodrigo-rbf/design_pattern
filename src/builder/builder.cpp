
#include "builder/builder.hpp"

using namespace std;


string HtmlElement::str(int indent = 0) const{
    ostringstream oss;
    string i(indent_size*indent, ' ');
    oss << i << "<" << name << ">" << endl;
    if(text.size() > 0)
        oss << string(indent_size*(indent+1), ' ') << text << endl;
    
    for (const auto& e : elements)
        oss << e.str(indent+1);
    
    oss<< i << "</" << name << ">" << endl;

    return oss.str();
}

unique_ptr<HtmlElement> HtmlElement::build(const string& root_name)
{
    return make_unique<HtmlElement>(root_name, "");
}


HtmlBuilder& HtmlBuilder::add_child(string child_name, string child_text)
{
    HtmlElement e{ child_name, child_text };
    root.elements.emplace_back(e);
    return *this;
}

// pointer based
HtmlBuilder* HtmlBuilder::add_child_2(string child_name, string child_text)
{
    HtmlElement e{ child_name, child_text };
    root.elements.emplace_back(e);
    return this;
}

string HtmlBuilder::str()
{
    return root.str();
}