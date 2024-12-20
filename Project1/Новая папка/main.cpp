#include "phonebook.h"

int main() {
    setlocale(LC_ALL, "Russian");
    vector<PhoneEntry> phoneBook = readPhoneBook("phonebook.txt");

    if (phoneBook.empty()) {
        cout << "Файл телефонной книги пуст." << endl;
        return 1;
    }

    string name;
    cout << "Введите фамилию абонента: ";
    getline(cin, name);

    PhoneEntry entry = findEntryByName(phoneBook, name);

    if (!entry.name.empty()) {
        if (isValidPhoneNumber(entry.phone)) {
            cout << "Номер телефона: " << entry.phone << endl;
        }
        else {
            cout << "Данные в файле некорректны." << endl;
        }
    }
    else {
        cout << "Абонент не найден." << endl;
    }

    return 0;
}

