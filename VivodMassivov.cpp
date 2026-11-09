#include <iostream>
#include <limits>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
    for (int i = 0; i < actual_size; i++)
    {
        if (i > 0) std::cout << ' ';
        if (i < logical_size) std::cout << arr[i];
        else std::cout << '_';
    }
}

int readInt(const char* prompt)
{
    int value;
    while (true)
    {
        std::cout << prompt;
        if (std::cin >> value)
            return value;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка ввода: нужно целое число. Попробуйте ещё раз.\n";
    }
}

int main()
{
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif

    int actual_size = readInt("Введите фактический размер массива: ");
    int logical_size = readInt("Введите логический размер массива: ");

    if (logical_size > actual_size)
    {
        std::cout << "Ошибка! Логический размер массива не может превышать фактический!"
                  << std::endl;
        return 0;
    }

    int* arr = new int[actual_size];

    for (int i = 0; i < logical_size; i++)
    {
        std::string prompt = "Введите arr[" + std::to_string(i) + "]: ";
        arr[i] = readInt(prompt.c_str());
    }

    std::cout << "Динамический массив: ";
    print_dynamic_array(arr, logical_size, actual_size);
    std::cout << std::endl;

    delete[] arr;
    return 0;
}