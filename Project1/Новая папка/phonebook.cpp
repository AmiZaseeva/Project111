#include "phonebook.h"

vector<PhoneEntry> readPhoneBook(const string& filename) {
    vector<PhoneEntry> phoneBook;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            size_t delimiter = line.find('-');
            if (delimiter != string::npos) {
                PhoneEntry entry;
                entry.name = line.substr(0, delimiter);
                entry.phone = line.substr(delimiter + 1);
                phoneBook.push_back(entry);
            }
        }
        file.close();
    }
    return phoneBook;
}

bool isValidPhoneNumber(const string& phoneNumber) {
    for (char c : phoneNumber) {
        if (!(isdigit(c) || c == '+' || c == ' ' || (c >= '0' && c <= '9'))) {
            return false;
        }
    }
    return true;
}

PhoneEntry findEntryByName(const vector<PhoneEntry>& phoneBook, const string& name) {
    for (const PhoneEntry& entry : phoneBook) {
        if (entry.name == name) {
            return entry;
        }
    }
    PhoneEntry emptyEntry;
    emptyEntry.name = "";
    emptyEntry.phone = "";
    return emptyEntry;
}