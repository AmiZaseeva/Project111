#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct PhoneEntry {
    string name;
    string phone;
};

vector<PhoneEntry> readPhoneBook(const string& filename);
bool isValidPhoneNumber(const string& phoneNumber);
PhoneEntry findEntryByName(const vector<PhoneEntry>& phoneBook, const string& name);

#endif // PHONEBOOK_H