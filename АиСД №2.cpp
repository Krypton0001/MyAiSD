// №1-2
#include <iostream>
using namespace std;

int main()
{
	// №1
	int a = 0;
	int *b = &a;
	setlocale(LC_ALL, "Russian");
	cout << "Введите значение *b: ";
	while (!(cin >> *b))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка ввода. Пожалуйста, повторите попытку.";
		cout << "\nВведите значение *b: ";
	}
	system("cls");
	cout << "Значение *b: " << *b << endl;
	cout << "Значение а: " << a << endl;
	system("pause");
	system("cls");
	// №2
	int &c = a;
	cout << "а = " << a << endl;
	cout << "Изменение значения переменной при помощи указателля (*b).\n"
		 << "Введите новое значение а: "; 
	while (!(cin >> *b))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "\nОшибка ввода. Пожалуйста, повторите попытку.\n";
		cout << "\nВведите новое значение а: ";
	}
	cout << "а = " << a << endl;
	cout << "\nИзменение значения переменной при помощи ссылки (с).\n"
		 << "Введите новое значение а: "; 
	while (!(cin >> c))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "\nОшибка ввода. Пожалуйста, повторите попытку.\n";
		cout << "\nВведите новое значение а: ";
	}
	cout << "а = " << a << endl;
	system("pause");
	return 0;
}


// 3-4
#include <iostream>
using namespace std;

int main()
{
	int * pInt = NULL;
	for (int i(0);; i++)
	{
		pInt = new int[10000000];
	}
	delete[] pInt;
	system("pause");
	return 0;
}


//5-6
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void output(int *Array, int n);
int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	system("cls");
	cout << "Введите размер массива." << endl;
	while (!(cin >> n) || n <= 1)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Поменяйте данные." << endl;
		cout << "Введите размер массива." << endl;
	}
	system("cls");
	int *A;
	A = new int[n];
	srand(time(NULL));
	for (int i(0); i < n; i++)
	{
		*(A + i) = rand() % 20 - 10;
	}
	cout << "Массив, заполненный случайными числами: "; output(A, n); cout << endl;
	delete[] A;
	A = NULL;
	system("pause");
	return 0;
}


void output(int *Array, int n)
{
	for (int i(0); i < n; i++)
	{
		cout << *(Array + i) << " ";
	}
}
