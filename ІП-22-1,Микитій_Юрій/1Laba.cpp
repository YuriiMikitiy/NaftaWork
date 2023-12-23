#include <iostream>
#include <locale>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "ukr"); // Встановлення локалізації для коректного виводу символів на українському
	cout << "1. Завдання: " << endl;

	int arr[14] = { 2,6,8,0,6,-9,-5,8,25,75,-9,12,-90, 25 }; // Створення масиву з 14 елементів

	int count = 0, sum = 0;

	for (int i = 0; i < 14; i++)
	{
		if (arr[i] < 0)
		{
			break; // Виходимо з циклу, якщо зустрічено від'ємний елемент
		}
		sum += arr[i]; // Додаємо елемент до суми
		count++; // Збільшуємо лічильник
	}
	cout << "Сума: " << sum << endl; // Виводимо суму
	cout << "Кiлькiсть елементiв: " << count << endl; // Виводимо кількість елементів


	cout << "\n\n2. Завдання: " << endl;

	int arr2[5][7];

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			arr2[i][j] = rand() % 101 - 50; // Генеруємо випадкові числа від -50 до 50 і заповнюємо масив
		}
	}

	int SumAbsValue = 0;

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			if (arr2[i][j] < 0)
			{
				SumAbsValue += abs(arr2[i][j]); // Додаємо абсолютне значення від'ємного елемента до суми
			}
		}
	}

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			cout << arr2[i][j] << "\t"; // Виводимо елементи масиву arr2
		}
		cout << endl;
	}

	cout << "Сума абсолютних значень вiдємних елементiв: " << SumAbsValue << endl; // Виводимо суму абсолютних значень від'ємних елементів
}
