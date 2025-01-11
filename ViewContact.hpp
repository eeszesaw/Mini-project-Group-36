#include <string>

using namespace std; 

class Contact {
public:
    string name;
    string phone_number;
    string email;
    string birthday;
    string note;

    Contact();
    Contact(const string& name, const string& phone, const string& email, const string& birthday, const string& note);
    void display() const;
};
