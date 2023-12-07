/*
TODO:
- Listar contatos {
    - Organizar contatos por diferentes categorias
}
- Armazenamento persistente
- Validação de entradas
- Interface gráfica
*/

#include <iostream>
#include <vector>
#include <regex>
#include <algorithm>

#ifdef _WIN32
#include <windows.h>
#elif defined(__linux__)
#include <cstdlib>
#endif

void clearScreen() {
#ifdef _WIN32
    // Clear the screen on Windows
    system("cls");
#elif defined(__linux__)
    // Clear the screen on Linux
    system("clear");
#endif
}

using namespace std;

bool validateEmail(const string &email) {
    // Regular expression to validate a simple email
    regex emailPattern("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");

    // Test the email against the regular expression
    return regex_match(email, emailPattern);
}

bool validateChoice() {
    char option;

    do {
        cout << "Are you sure? (y/n)" << endl;
        cin >> option;
        switch (option) {
            case 'y':
                return true;
                break;
            case 'n':
                return false;
                break;
            default:
                cout << "Invalid input" << endl;
                break;
        }
    } while (option != 'y' && option != 'n');
}

class Contact {
public:
    // Create a contact with all information.
    Contact(const string &name, const string &number, const string &email = "")
        : name(name), number(number), email(email) {}

    const string &getName() const { return name; }
    const string &getNumber() const { return number; }
    const string &getEmail() const { return email; }

    void editContact() {
        int option;

        cout << "\nChoose what to edit:" << endl;
        cout << "1. Name" << endl;
        cout << "2. Number" << endl;
        cout << "3. Email" << endl;
        cout << "0. Cancel" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "New name: ";
                cin >> name;
                break;
            case 2:
                cout << "New number: ";
                cin >> number;
                break;
            case 3:
                cout << "New email: ";
                cin >> email;
                break;
            case 0:
                cout << "Edit canceled." << endl;
                break;
            default:
                cout << "Invalid option. Edit canceled." << endl;
                break;
        }
    }

    void displayContact() const {
        cout << "Name: " << name << endl;
        cout << "Number: " << number << endl;
        if (!email.empty()) {
            cout << "Email: " << email << endl;
        }
        cout << "\n";
    }

    size_t getSimilarity(const string &term) const {
        // Calculate similarity between the contact's name and the search term
        size_t similarity = 0;
        for (size_t i = 0; i < min(name.size(), term.size()); ++i) {
            if (tolower(name[i]) == tolower(term[i])) {
                ++similarity;
            } else {
                break;  // Stop counting at the first difference
            }
        }
        return similarity;
    }
private:
    string name;
    string number;
    string email;
};

class Agenda {
public:
    void addContact(const string &name, const string &number, const string &email) {
        contacts.emplace_back(Contact(name, number, email));
    }

    void listContacts() {
        clearScreen();
        int size = contacts.size();

        for (int i = 0; i < size; i++) {
            cout << "ID: " << i + 1 << endl;
            contacts[i].displayContact();
        }

        int option;
        int id;
        cout << "1 - Delete contact." << endl;
        cout << "2 - Edit contact." << endl;
        cout << "0 - Back to menu." << endl;
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Contact ID: ";
                cin >> id;
                deleteContact(id - 1);
                break;

            case 2:
                cout << "Contact ID: ";
                cin >> id;
                editContact(id - 1);
                break;

            case 0:
                break;

            default:
                cout << "Invalid option. Try again." << endl;
                break;
        }
    }

    void searchContact() {
        string term;
        cout << "\nEnter the search term: ";
        cin >> term;

        vector<pair<size_t, const Contact*>> results;

        for (size_t i = 0; i < contacts.size(); i++) {
            results.emplace_back(contacts[i].getSimilarity(term), &contacts[i]);
        }

        // Sort the results based on similarity in descending order
        sort(results.rbegin(), results.rend(), [](const auto &a, const auto &b) {
            return a.first < b.first;
        });

        clearScreen();
        cout << "Search Results for '" << term << "':" << endl;

        for (const auto &result : results) {
            if (result.first > 0) {
                result.second->displayContact();
            }
        }

        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }

    void editContact(size_t pos) {
        if (pos < contacts.size()) {
            Contact &contact = contacts[pos];
            contact.editContact();
            cout << "Contact edited successfully." << endl;
        } else {
            cout << "Invalid position." << endl;
        }
        listContacts();
    }

    void deleteContact(const size_t &pos) {
        if (pos < contacts.size()) {
            if (validateChoice()) {
                contacts.erase(contacts.begin() + pos);
                cout << "Contact in position " << pos << " deleted." << endl;
                listContacts();
            } else {
                listContacts();
            }
        } else {
            cout << "Invalid position." << endl;
            listContacts();
        }
    }

private:
    vector<Contact> contacts;
};

void addContact(Agenda &agenda) {
    string name, number, email;
    cout << "\nName:";
    cin >> name;
    cout << "Number:";
    cin >> number;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Email:";
    getline(cin, email);

    if (name.empty() || number.empty()) {
        cout << "Error! Fill the name and number." << endl;
        return;
    }
    if (validateEmail(email) || email.empty()) {
        agenda.addContact(name, number, email);
    } else {
        cout << "Error! Invalid Email." << endl;
        return;
    }
}

void mainMenu(Agenda &agenda) {
    int option;

    do {
        clearScreen();
        cout << "\n--- Menu ---" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Search Contact" << endl;
        cout << "3. List Contacts" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case 1:
                addContact(agenda);
                break;

            case 2:
                agenda.searchContact();
                break;

            case 3:
                agenda.listContacts();
                break;

            case 0:
                break;

            default:
                cout << "Invalid option. Try again." << endl;
                break;
        }

    } while (option != 0);
}

int main() {
    Agenda agenda;

    mainMenu(agenda);

    return 0;
}
