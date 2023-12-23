#include <iostream>
#include <cstdlib>   // ��� ������������ ������� rand()
#include <ctime>     // ��� ������������ ������� time()
#include <string>


using namespace std;

string foo4(int arr[], int N);
string foo30(int arr[], int N);
void InsertSorter(int a[], int n);

void main() 
{
	// ��� ��������� ���������� ����� �� ����� ��������� ����
	srand(static_cast<unsigned int>(std::time(nullptr)));

	//1.-----------------------------
	int arr[] = { 98, 48, 45, 11, 7, 3};
	for (int i = 0; i < 4; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	foo4(arr, 4);  //��������� ������� ���������� 
	
	for (int i = 0; i < 4; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "----------------------------" << endl;


	//2.
	const int arraySize = 30;
	int myArray[arraySize];

	// ���������� ������ ����������� ������� �� 0 �� 100
	for (int i = 0; i < arraySize; ++i) {
		myArray[i] = rand() % 101;  // �������� ��������� ����� �� 0 �� 100
	}
	// ��������� ����������� ������ �� �����
	for (int i = 0; i < arraySize; ++i) {
		cout << myArray[i] << " ";
	}
	cout << endl;

	foo30(myArray, 30);   //��������� ������� ���������� 

	// ��������� ������ �� �����
	for (int i = 0; i < arraySize; ++i) {
		cout << myArray[i] << " ";
	}
	cout << endl;
	cout << "----------------------------" << endl;

	//3.
	int arr3[] = { 22, 19, 9, 8, 11, 14 };
	int size = sizeof(arr3) / sizeof(arr[0]);

	InsertSorter(arr3, size);

	// Print the sorted array
	std::cout << "Array3:" << std::endl;
	for (int i = 0; i < size; i++) {
		cout << arr3[i] << " ";
	}

}

string foo4(int *arr, int N) {
	if (N!=4)
	{
		return "Error!";
	}
	else {
		for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < N - i - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
		return "GOOD!";
	}
}

string foo30(int *arr2, int N) {
	if (N != 30)
	{
		return "Error!";
	}
	else {
		for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < N - i - 1; j++)
			{
				if (arr2[j] > arr2[j + 1])
				{
					int temp = arr2[j];
					arr2[j] = arr2[j + 1];
					arr2[j + 1] = temp;
				}
			}
		}
		return "GOOD!";
	}
}

void InsertSorter(int arr[], int n) {
	int temp, iPrev;
	for (int i = 1; i < n; i++) {
		temp = arr[i];
		iPrev = i - 1;

		std::cout << "Step " << i << "\n- compere element:" << std::endl;

		// ������� ����� : ��������� �� ���������� ������� �� ���� ����
			while (iPrev >= 0 && arr[iPrev] > temp) {
				// ���� ������ ������������ �������� � ����� � �� ����� ����
				// �� �������� �������� �����, �� "temp" (�������� ����)

				// ������� ������ ������� ������, ��������� ���� ��� "temp"
				arr[iPrev + 1] = arr[iPrev];

				// ������� "temp" (�������� ����) �� �������� ����
				arr[iPrev] = temp;

				// �������� ������ ��� �������� �� ������������ ��������
				iPrev--;
			}
	}
}