// �1-2
#include <iostream>
using namespace std;

int main()
{
	// �1
	int a = 0;
	int *b = &a;
	setlocale(LC_ALL, "Russian");
	cout << "������� �������� *b: ";
	while (!(cin >> *b))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "������ �����. ����������, ��������� �������.";
		cout << "\n������� �������� *b: ";
	}
	system("cls");
	cout << "�������� *b: " << *b << endl;
	cout << "�������� �: " << a << endl;
	system("pause");
	system("cls");
	// �2
	int &c = a;
	cout << "� = " << a << endl;
	cout << "��������� �������� ���������� ��� ������ ���������� (*b).\n"
		 << "������� ����� �������� �: "; 
	while (!(cin >> *b))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "\n������ �����. ����������, ��������� �������.\n";
		cout << "\n������� ����� �������� �: ";
	}
	cout << "� = " << a << endl;
	cout << "\n��������� �������� ���������� ��� ������ ������ (�).\n"
		 << "������� ����� �������� �: "; 
	while (!(cin >> c))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "\n������ �����. ����������, ��������� �������.\n";
		cout << "\n������� ����� �������� �: ";
	}
	cout << "� = " << a << endl;
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
	cout << "������� ������ �������." << endl;
	while (!(cin >> n) || n <= 1)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "��������� ������." << endl;
		cout << "������� ������ �������." << endl;
	}
	system("cls");
	int *A;
	A = new int[n];
	srand(time(NULL));
	for (int i(0); i < n; i++)
	{
		*(A + i) = rand() % 20 - 10;
	}
	cout << "������, ����������� ���������� �������: "; output(A, n); cout << endl;
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
