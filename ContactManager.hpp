class ContactManager {
private:
    std::vector<Contact> contacts;

public:
    void addContact(const Contact& contact);
    void viewAllContacts() const;
    Contact* searchContact(const std::string& name);
    bool editContact(const std::string& name);
    bool deleteContact(const std::string& name);
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};
