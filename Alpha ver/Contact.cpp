#include "Contact.hpp"

Contact::Contact(const std::string& name, const std::string& phoneNumber, const std::string& email)
    : name(name), phoneNumber(phoneNumber), email(email) {}

std::string Contact::getName() const {
    return name;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}

std::string Contact::getEmail() const {
    return email;
}

void Contact::setName(const std::string& name) {
    this->name = name;
}

void Contact::setPhoneNumber(const std::string& phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Contact::setEmail(const std::string& email) {
    this->email = email;
}
