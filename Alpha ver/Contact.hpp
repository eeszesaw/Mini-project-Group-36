#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
    Contact(const std::string& name, const std::string& phoneNumber, const std::string& email);

    std::string getName() const;
    std::string getPhoneNumber() const;
    std::string getEmail() const;

    void setName(const std::string& name);
    void setPhoneNumber(const std::string& phoneNumber);
    void setEmail(const std::string& email);

private:
    std::string name;
    std::string phoneNumber;
    std::string email;
};

#endif // CONTACT_HPP
