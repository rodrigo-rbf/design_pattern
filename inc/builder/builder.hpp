#ifndef __BUILDER_HPP__
#define __BUILDER_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
using namespace std;

namespace html{

    class HtmlBuilder;

    class HtmlElement{
        public:
            HtmlElement(){};
            HtmlElement(const string& name, const string& text) : 
                name(name),
                text(text)
            {}

            string str(int indent) const;
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


    class Tag
    {
        public:
            Tag(const std::string& name, const std::string& text) :
            name{name},
            text{text}
            {}

            Tag(const std::string& name, const std::vector<Tag>& children) :
            name{name},
            children{children}
            {}

            std::string name;
            std::string text;
            std::vector<Tag> children;
            std::vector<std::pair<std::string, std::string>> attributes;

            protected:
                friend std::ostream& operator<<(std::ostream& os, const Tag& tag);
   
    };
    std::ostream &operator<<(std::ostream &os, const html::Tag &tag)
    {
        os << "<" << tag.name;

        for (const auto& att : tag.attributes)
            os << " " << att.first << "=\"" << att.second << "\"";

        if (tag.children.size() == 0 && tag.text.length() == 0)
            os << "/>" << std::endl; 
        else
            {
            os << ">" << std::endl;

            if (tag.text.length())
                os << tag.text << std::endl;

            for (const auto& child : tag.children)
                os << child;

            os << "</" << tag.name << ">" << std::endl;
            }

        return os;
    }

    class P : public Tag
    {
        public: 
            explicit P(const std::string& text):Tag{"p", text}
            {}

            P(std::initializer_list<Tag> children):Tag("p", children)
            {}

    };

    class IMG : public Tag
    {
        public:
            explicit IMG(const std::string& url):Tag{"img", ""}
            {
                attributes.emplace_back(make_pair("src", url));
            }
    };






};
#endif