##include "Contact.hpp"

// Constructor
Contact::Contact(const std::string& firstName, const std::string& lastName,
                 const std::string& phone, const std::string& email)
    : firstName(firstName), lastName(lastName), phone(phone), email(email) {}

// Getters
std::string Contact::getFullName() const {
    return firstName + " " + lastName;
}

std::string Contact::getFirstName() const {
    return firstName;
}

std::string Contact::getLastName() const {
    return lastName;
}

std::string Contact::getPhone() const {
    return phone;
}

std::string Contact::getEmail() const {
    return email;
}

// Setters
void Contact::setFirstName(const std::string& firstName) {
    this->firstName = firstName;
}

void Contact::setLastName(const std::string& lastName) {
    this->lastName = lastName;
}

void Contact::setPhone(const std::string& phone) {
    this->phone = phone;
}

void Contact::setEmail(const std::string& email) {
    this->email = email;
}

