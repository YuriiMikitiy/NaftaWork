#include <iostream>
#include <locale>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "ukr"); // ������������ ���������� ��� ���������� ������ ������� �� �����������
	cout << "1. ��������: " << endl;

	int arr[14] = { 2,6,8,0,6,-9,-5,8,25,75,-9,12,-90, 25 }; // ��������� ������ � 14 ��������

	int count = 0, sum = 0;

	for (int i = 0; i < 14; i++)
	{
		if (arr[i] < 0)
		{
			break; // �������� � �����, ���� ��������� ��'����� �������
		}
		sum += arr[i]; // ������ ������� �� ����
		count++; // �������� ��������
	}
	cout << "����: " << sum << endl; // �������� ����
	cout << "�i���i��� �������i�: " << count << endl; // �������� ������� ��������


	cout << "\n\n2. ��������: " << endl;

	int arr2[5][7];

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			arr2[i][j] = rand() % 101 - 50; // �������� �������� ����� �� -50 �� 50 � ���������� �����
		}
	}

	int SumAbsValue = 0;

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			if (arr2[i][j] < 0)
			{
				SumAbsValue += abs(arr2[i][j]); // ������ ��������� �������� ��'������ �������� �� ����
			}
		}
	}

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			cout << arr2[i][j] << "\t"; // �������� �������� ������ arr2
		}
		cout << endl;
	}

	cout << "���� ���������� ������� �i����� �������i�: " << SumAbsValue << endl; // �������� ���� ���������� ������� ��'����� ��������
}
