#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string phone;
    std::string email;

public:
    Contact() = default;

    Contact(const std::string& firstName, const std::string& lastName, const std::string& phone, const std::string& email)
        : firstName(firstName), lastName(lastName), phone(phone), email(email) {}

    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    std::string getPhone() const { return phone; }
    std::string getEmail() const { return email; }

    void setFirstName(const std::string& fName) { firstName = fName; }
    void setLastName(const std::string& lName) { lastName = lName; }
    void setPhone(const std::string& phoneNumber) { phone = phoneNumber; }
    void setEmail(const std::string& emailAddress) { email = emailAddress; }

    std::string getFullName() const { return firstName + " " + lastName; }

    void display() const {
        std::cout << "Name: " << firstName << " " << lastName << "\n";
        std::cout << "Phone: " << phone << "\n";
        std::cout << "Email: " << email << "\n";
    }
};

#endif // CONTACT_HPP
