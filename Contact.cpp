/*Written by: CHONG JUN XIANG 23301918
Function purpose: Implements the methods of the Contact class.*/

#include "Contact.hpp"
#include <iostream>

using namespace std;


Contact::Contact(const string& firstName, const string& lastName, const string& phone, const string& email,
                 const string& birthday, const string& note)
    : firstName(firstName), lastName(lastName), phone(phone), email(email), birthday(birthday), note(note) {}


string Contact::getFirstName() const { return firstName; }
string Contact::getLastName() const { return lastName; }
string Contact::getPhone() const { return phone; }
string Contact::getEmail() const { return email; }
string Contact::getBirthday() const { return birthday; }
string Contact::getNote() const { return note; }


void Contact::setFirstName(const string& firstName) { this->firstName = firstName; }
void Contact::setLastName(const string& lastName) { this->lastName = lastName; }
void Contact::setPhone(const string& phone) { this->phone = phone; }
void Contact::setEmail(const string& email) { this->email = email; }
void Contact::setBirthday(const string& birthday) { this->birthday = birthday; }
void Contact::setNote(const string& note) { this->note = note; }


void Contact::display() const {
    cout << "Name: " << firstName << " " << lastName << endl;
    cout << "Phone: " << phone << endl;
    cout << "Email: " << email << endl;
    cout << "Birthday: " << birthday << endl;
    cout << "Note: " << note << endl;
}
