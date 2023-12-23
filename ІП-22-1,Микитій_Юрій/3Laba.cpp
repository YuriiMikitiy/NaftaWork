#include <iostream>
#include <locale>

using namespace std;

void decimalToOctal(int n) {
    // Базовий випадок: якщо число менше або дорівнює 7, виводимо його
    if (n <= 7) {
        std::cout << n;
    }
    else {
        // Рекурсивний випадок: ділимо число на 8 і викликаємо функцію з новим значенням
        decimalToOctal(n / 8);
        // Виводимо остачу від ділення (цифру в восьмеричній системі)
        std::cout << n % 8;
    }
}

int main() {
    setlocale(LC_CTYPE, "ukr"); //для Укр мови в консолі
    int num;
    std::cout << "Введiть натуральне число: ";
    std::cin >> num;

    if (num < 0) {
        std::cout << "Будь ласка, введiть натуральне число." << std::endl;
    }
    else {
        std::cout << "Число у вiсiмковiй системi: ";
        decimalToOctal(num);
        std::cout << std::endl;
    }

    return 0;
}
