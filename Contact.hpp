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
    // Constructor
    Contact(const std::string& firstName = "",
            const std::string& lastName = "",
            const std::string& phone = "",
            const std::string& email = "")
        : firstName(firstName), lastName(lastName), phone(phone), email(email) {}

    // Getters
    std::string getFullName() const {
        return firstName + " " + lastName;
    }
    std::string getPhone() const {
        return phone;
    }
    std::string getEmail() const {
        return email;
    }

    // Setters
    void setFirstName(const std::string& firstName) {
        this->firstName = firstName;
    }
    void setLastName(const std::string& lastName) {
        this->lastName = lastName;
    }
    void setPhone(const std::string& phone) {
        this->phone = phone;
    }
    void setEmail(const std::string& email) {
        this->email = email;
    }

    // Display contact information
    void display() const {
        std::cout << "Name: " << firstName << " " << lastName << "\n";
        std::cout << "Phone: " << phone << "\n";
        std::cout << "Email: " << email << "\n";
    }
};

#endif // CONTACT_HPP
