#include <iostream>
#include <vector>

// ������� ��� ����� ������� ���� ��������
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// ������� ��� ��������� ������ ��� �������� ����������
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// ������� ������� �������� ����������
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// ������� ��� ������ ���� ������������ ��������
void merge(std::vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // �������� ������ ��� ��������� ���� ��������
    std::vector<int> leftArray(n1);
    std::vector<int> rightArray(n2);

    // ������� ��� � �������� ������ leftArray �� rightArray
    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[middle + 1 + j];

    // ������ ���������� ������ � �������� ����� arr
    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        }
        else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // ������� ������� leftArray, ���� ����� �
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // ������� ������� rightArray, ���� ����� �
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

// ������� ������� ������ ����������
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        // ��������� �������� ������
        int middle = left + (right - left) / 2;

        // ������� ����� �� ����� ��������
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // ������ ������������ ������
        merge(arr, left, middle, right);
    }
}

int main() {
    // ������� ������������ �������� ����������
    std::cout << "----------1:\n";
    std::vector<int> array = { 12, 8, 9, 11, 6, 2 };
    int n = array.size();

    std::cout << "Original array: ";
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    quickSort(array, 0, n - 1);

    std::cout << "Sorted array: ";
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // ������� ������������ ������ ����������
    std::cout << "\n----------2:\n";

    std::vector<int> array2 = { 12, 8, 9, 6, 2 };
    int n2 = array2.size();

    std::cout << "Original array: ";
    for (int num : array2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    mergeSort(array2, 0, n2 - 1);

    std::cout << "Sorted array: ";
    for (int num : array2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
