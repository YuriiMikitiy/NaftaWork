#include <iostream>
#include <locale>

using namespace std;

void decimalToOctal(int n) {
    // ������� �������: ���� ����� ����� ��� ������� 7, �������� ����
    if (n <= 7) {
        std::cout << n;
    }
    else {
        // ����������� �������: ����� ����� �� 8 � ��������� ������� � ����� ���������
        decimalToOctal(n / 8);
        // �������� ������ �� ������ (����� � ����������� ������)
        std::cout << n % 8;
    }
}

int main() {
    setlocale(LC_CTYPE, "ukr"); //��� ��� ���� � ������
    int num;
    std::cout << "����i�� ���������� �����: ";
    std::cin >> num;

    if (num < 0) {
        std::cout << "���� �����, ����i�� ���������� �����." << std::endl;
    }
    else {
        std::cout << "����� � �i�i����i� ������i: ";
        decimalToOctal(num);
        std::cout << std::endl;
    }

    return 0;
}
