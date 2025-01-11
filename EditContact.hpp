#ifndef EDITCONTACT_HPP
#define EDITCONTACT_HPP

#include <iostream>
#include <string>
#include <unordered_map>

class Contact {
public:
    std::string name;
    std::string phoneNumber;
    std::string email;

    Contact(std::string n, std::string p, std::string e);
};

class ContactDirectory {
private:
    std::unordered_map<std::string, Contact> contacts;

public:
    void editContact(const std::string& name);
};

#endif 