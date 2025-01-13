void ContactManager::saveToFile(const string& filename) const {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error opening file for writing: " << filename << '\n';
        return;
    }

    for (const auto& contact : contacts) {
        outFile << contact.getFirstName() << '\n'
                << contact.getLastName() << '\n'
                << contact.getPhone() << '\n'
                << contact.getEmail() << '\n';
    }
}
