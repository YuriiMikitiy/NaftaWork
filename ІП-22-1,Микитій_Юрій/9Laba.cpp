#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "ukr");
    // �������� ������ ��������
    int k;
    cout << "������ ��� ����� ��������: ";
    cin >> k;

    // ���������� ������ ������
    int n = (int)(20 + 0.6 * k);

    // ���������� ������ ����������� �������
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 20 + 10;
    }
    // ��������� �������� ������
    cout << "�������� ������:" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    // ³����������� ������ �� ������� ���������
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // ����������� ����� � ������� ��� ������� ������
    if (k % 2 != 0) {
        // ������������� ����� ���������������� ������
        int key = a[n / 2];
        int low = 0;
        int high = n / 2 - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (a[mid] == key) {
                cout << "�������� ����: " << key << endl;
                return 0;
            }
            else if (a[mid] < key) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        cout << "���� �� ��������." << endl;
    }
    else {
        // ������������� ����� ������� ������
        int key = a[n / 2];
        for (int i = 0; i < n / 2; i++) {
            if (a[i] == key) {
                cout << "�������� ����: " << key << endl;
                return 0;
            }
        }
        cout << "���� �� ��������." << endl;
    }

    delete[] a;
    return 0;
}