struct Contact;


bool isValidPhone(const std::string& phone);  // Validate phone number
bool isValidEmail(const std::string& email);  // Validate email address
bool isValidDate(const std::string& date);    // Validate date format (YYYY-MM-DD)
void getInput(std::string& input, const std::string& prompt);  // Get input from the user
void displayContact(const Contact& contact);  // Display a contact's details
bool validateInput(const std::string& input, bool(*validationFn)(const std::string&), const std::string& errorMessage);  // Validate input with a given function
void addContact(std::vector<Contact>& contacts);  // Add a new contact to the list
