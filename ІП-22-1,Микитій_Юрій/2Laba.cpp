#include <iostream>
#include <locale>

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "ukr"); //для Укр мови в консолі

	cout << "Введiть розмiрнiсть масиву: ";
	int N;
	cin >> N;

	int* arr = new int[N];  //створення динамічного масиву
	
	cout << "Введiть данi в масив:";
	for (int i = 0; i < N; i++)   //введення значень у масив 
	{
		cout << "Комiрка [" << i << "]: ";
		cin >> arr[i];
	}

	//Завдання 1--------------------------------------------------------------
    int* index = new int[12];
    int count = 0;
    for (int i = 1; i < N; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            // Перевірка, чи потрібно розширити масив index
            if (count >= 11) {
                int* new_index = new int[count * 2]; // Створення нового більшого масиву
                for (int j = 0; j < count; j++) {
                    new_index[j] = index[j]; // Копіювання даних зі старого масиву
                }
                delete[] index; // Звільнення пам'яті, відведеної старому масиву
                index = new_index; // Перенесення вказівника на новий масив
            }

            index[count] = i;
            count++;
        }
    }

    // Виведення номерів елементів, що відповідають умові
    cout << "Номери елементiв, якi вiдповiдають умовi: ";
    for (int i = 0; i < count; i++)
    {
        cout << index[i] << " ";
    }
    cout << endl;
    cout << "Кiлькiсть елементiв, якi вiдповiдають умовi: ";
    cout << count;

    // Пам'ять треба звільнити після використання
    delete[] arr;
    delete[] index;
}