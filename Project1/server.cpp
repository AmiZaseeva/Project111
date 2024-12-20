#include <iostream>
#include <string>
#include <map>

// 1. Шаблон функции для проверки уникальности
template <typename T>
bool areUnique(const T& a, const T& b) {
    return a != b;
}

// 2. Класс для хранения массива значений и проверки уникальности
template <typename T>
class ArrayChecker {
private:
    T* arr;
    size_t size;

public:
    ArrayChecker(T* arr, size_t size) : arr(arr), size(size) {}

    bool areAllUnique() const {
        if (size <= 1) {
            return true; // Пустой или единичный массив всегда уникален
        }
        for (size_t i = 0; i < size - 1; ++i) {
            for (size_t j = i + 1; j < size; ++j) {
                if (!areUnique(arr[i], arr[j])) {
                    return false; // Найдены дубликаты
                }
            }
        }
        return true; // Все значения уникальны
    }
};

// 3. Специализация для типа string (не требуется, так как шаблон уже работает)
 template <>
 bool areUnique<std::string>(const std::string& a, const std::string& b) {
     return a != b;
 }


// 4. Специализация класса для типа char с анализом частоты символов
template <>
class ArrayChecker<char> {
private:
    char* arr;
    size_t size;

public:
    ArrayChecker(char* arr, size_t size) : arr(arr), size(size) {}

    std::map<char, int> getFrequency() const {
        std::map<char, int> freq;
        for (size_t i = 0; i < size; ++i) {
            freq[arr[i]]++;
        }
        return freq;
    }

    bool areAllUnique() const {
        if (size <= 1) {
            return true; // Пустой или единичный массив всегда уникален
        }
        for (size_t i = 0; i < size - 1; ++i) {
            for (size_t j = i + 1; j < size; ++j) {
                if (arr[i] == arr[j]) {
                    return false; // Найдены дубликаты
                }
            }
        }
        return true; // Все значения уникальны
    }
};

int main() {
    // Проверка для int
    int intArray[] = { 1, 2, 3, 4, 5 };
    ArrayChecker<int> intChecker(intArray, 5);
    std::cout << "Int array is unique: " << intChecker.areAllUnique() << std::endl;

    int intArray2[] = { 1, 2, 3, 2, 5 };
    ArrayChecker<int> intChecker2(intArray2, 5);
    std::cout << "Int array is unique: " << intChecker2.areAllUnique() << std::endl;


    // Проверка для string
    std::string strArray[] = { "apple", "banana", "cherry" };
    ArrayChecker<std::string> strChecker(strArray, 3);
    std::cout << "String array is unique: " << strChecker.areAllUnique() << std::endl;

    std::string strArray2[] = { "apple", "banana", "apple" };
    ArrayChecker<std::string> strChecker2(strArray2, 3);
    std::cout << "String array is unique: " << strChecker2.areAllUnique() << std::endl;

    // Проверка для char (с частотой)
    char charArray[] = { 'a', 'b', 'c', 'a', 'd' };
    ArrayChecker<char> charChecker(charArray, 5);
    std::cout << "Char array is unique: " << charChecker.areAllUnique() << std::endl;
    std::map<char, int> freq = charChecker.getFrequency();
    std::cout << "Character frequencies: " << std::endl;
    for (const auto& pair : freq) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    char charArray2[] = { 'a', 'b', 'c','d','e' };
    ArrayChecker<char> charChecker2(charArray2, 5);
    std::cout << "Char array is unique: " << charChecker2.areAllUnique() << std::endl;

    return 0;
}
