#include <iostream>
#include <locale>

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "ukr"); //��� ��� ���� � ������

	cout << "����i�� ����i��i��� ������: ";
	int N;
	cin >> N;

	int* arr = new int[N];  //��������� ���������� ������
	
	cout << "����i�� ���i � �����:";
	for (int i = 0; i < N; i++)   //�������� ������� � ����� 
	{
		cout << "���i��� [" << i << "]: ";
		cin >> arr[i];
	}

	//�������� 1--------------------------------------------------------------
    int* index = new int[12];
    int count = 0;
    for (int i = 1; i < N; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            // ��������, �� ������� ��������� ����� index
            if (count >= 11) {
                int* new_index = new int[count * 2]; // ��������� ������ ������� ������
                for (int j = 0; j < count; j++) {
                    new_index[j] = index[j]; // ��������� ����� � ������� ������
                }
                delete[] index; // ��������� ���'��, �������� ������� ������
                index = new_index; // ����������� ��������� �� ����� �����
            }

            index[count] = i;
            count++;
        }
    }

    // ��������� ������ ��������, �� ���������� ����
    cout << "������ �������i�, ��i �i����i����� ����i: ";
    for (int i = 0; i < count; i++)
    {
        cout << index[i] << " ";
    }
    cout << endl;
    cout << "�i���i��� �������i�, ��i �i����i����� ����i: ";
    cout << count;

    // ���'��� ����� �������� ���� ������������
    delete[] arr;
    delete[] index;
}