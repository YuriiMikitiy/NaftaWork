#include <iostream>
#include <vector>
#include <locale>

void shellSort(std::vector<int>& arr) {
    int n = arr.size();

    // ���������� ��������� ��� ����������
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;

            // ��������� �������� � �������� �� �������
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}

int main() {
    setlocale(LC_CTYPE, "ukr");
    std::vector<int> arr = { 12, 8, 9, 11, 6, 2 };

    std::cout << "����� ����� �����������: ";
    for (int i : arr) {
        std::cout << i << " ";
    }

    shellSort(arr);

    std::cout << "\n����� �i��� �����������: ";
    for (int i : arr) {
        std::cout << i << " ";
    }

    return 0;
}
