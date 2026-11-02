#ifndef _INC_PROTOTYPE_CONTACT_HPP_
#define _INC_PROTOTYPE_CONTACT_HPP_

#include "iostream"
#include "string"





struct Address
{
    std::string street, city;
    int suite;

    Address(const std::string& street, const std::string& city, int suite) :
        street(street), city(city), suite(suite) {}

    friend std::ostream &operator << (std::ostream &os, const Address &address)
    {
        os << "street: " << address.street << ", city: " << address.city << ", suite: " << address.suite;
        return os;
    }

};

struct Contact
{
    std::string name;
    Address address;

    Contact(const std::string &name, const Address &address) :
        name(name), address(address) {}
    
    friend std::ostream &operator << (std::ostream &os, const Contact contact)
    {
        os << "Name: " << contact.name << ", Address: " << contact.address;
        return os;
    }
};








#endif