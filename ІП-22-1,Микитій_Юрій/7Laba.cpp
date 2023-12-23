#include <iostream>
#include <vector>
#include <locale>

void shellSort(std::vector<int>& arr) {
    int n = arr.size();

    // Визначення інтервалів для сортування
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;

            // Порівняння елементів в інтервалі та вставка
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

    std::cout << "Масив перед сортуванням: ";
    for (int i : arr) {
        std::cout << i << " ";
    }

    shellSort(arr);

    std::cout << "\nМасив пiсля сортуванням: ";
    for (int i : arr) {
        std::cout << i << " ";
    }

    return 0;
}
