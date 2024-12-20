#include "phonebook.h"

int main() {
    setlocale(LC_ALL, "Russian");
    vector<PhoneEntry> phoneBook = readPhoneBook("phonebook.txt");

    if (phoneBook.empty()) {
        cout << "���� ���������� ����� ����." << endl;
        return 1;
    }

    string name;
    cout << "������� ������� ��������: ";
    getline(cin, name);

    PhoneEntry entry = findEntryByName(phoneBook, name);

    if (!entry.name.empty()) {
        if (isValidPhoneNumber(entry.phone)) {
            cout << "����� ��������: " << entry.phone << endl;
        }
        else {
            cout << "������ � ����� �����������." << endl;
        }
    }
    else {
        cout << "������� �� ������." << endl;
    }

    return 0;
}

