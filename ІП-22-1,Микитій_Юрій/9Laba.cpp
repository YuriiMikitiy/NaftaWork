#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "ukr");
    // Введення номера студента
    int k;
    cout << "Введіть свій номер студента: ";
    cin >> k;

    // Обчислення розміру масиву
    int n = (int)(20 + 0.6 * k);

    // Заповнення масиву випадковими числами
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 20 + 10;
    }
    // Виведення елементів масиву
    cout << "Елементи масиву:" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    // Відсортування масиву за методом бульбашки
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // Знаходження ключа в середині лівої частини масиву
    if (k % 2 != 0) {
        // Використовуємо метод інтерполяційного пошуку
        int key = a[n / 2];
        int low = 0;
        int high = n / 2 - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (a[mid] == key) {
                cout << "Знайдено ключ: " << key << endl;
                return 0;
            }
            else if (a[mid] < key) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        cout << "Ключ не знайдено." << endl;
    }
    else {
        // Використовуємо метод лінійного пошуку
        int key = a[n / 2];
        for (int i = 0; i < n / 2; i++) {
            if (a[i] == key) {
                cout << "Знайдено ключ: " << key << endl;
                return 0;
            }
        }
        cout << "Ключ не знайдено." << endl;
    }

    delete[] a;
    return 0;
}