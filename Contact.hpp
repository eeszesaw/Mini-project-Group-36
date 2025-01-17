#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
using namespace std;

class Contact {
public:
    
    Contact(const string& firstName, const string& lastName, const string& phone, const string& email,
            const string& birthday, const string& note);

    
    string getFirstName() const;
    string getLastName() const;
    string getFullName() const {
        return firstName + " " + lastName;
    }
    string getPhone() const;
    string getEmail() const;
    string getBirthday() const;
    string getNote() const;

    
    void setFirstName(const string& firstName);
    void setLastName(const string& lastName);
    void setPhone(const string& phone);
    void setEmail(const string& email);
    void setBirthday(const string& birthday);
    void setNote(const string& note);

    // Display method
    void display() const;

private:
    string firstName;
    string lastName;
    string phone;
    string email;
    string birthday;
    string note;
};

#endif 
