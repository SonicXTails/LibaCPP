#include <windows.h>
#include <iostream>
#include <string>
#include <C:\WorkStringLiba\WorkWithDynamicLiba\Liba\Header.h>

typedef bool (*ContainsAllCharsFunc)(const char*, const char*);

int main() {
    setlocale(LC_ALL, "RUSSIAN");
    std::string inputString;
    std::string searchString;

    std::cout << "Введите строку: ";
    std::getline(std::cin, inputString);

    std::cout << "Введите символы для поиска: ";
    std::getline(std::cin, searchString);

    HINSTANCE load;
    load = LoadLibrary(L"WorkWithDynamicLiba.dll");
    if (load != NULL) {
        ContainsAllCharsFunc ContainsAllChars = (ContainsAllCharsFunc)GetProcAddress(load, "ContainsAllChars");

        if (ContainsAllChars != NULL) {
            bool result = ContainsAllChars(inputString.c_str(), searchString.c_str());
            std::cout << "Результат: " << (result ? "Все символы найдены." : "Не все символы найдены.") << std::endl;
        }
        else {
            std::cerr << "Функция не найдена." << std::endl;
        }

        FreeLibrary(load);
    }
    else {
        std::cerr << "DLL не найдена." << std::endl;
    }

    return 0;
}
