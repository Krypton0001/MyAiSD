// 1. ����� ���-�� ��������� ������� (�=10), ������������ ����� ����������� ��������

#include <iostream>
#include "conio.h"
using namespace std;

int main()
{
	const int n = 10;
	int Array[n];
	setlocale(LC_ALL, "Russian");

	// ���� �������
	cout << "��������� ������ ������ �������.\n";
	for (int i(0); i < n; i++)
	{
		cout << "[" << i + 1 << "]: ";
		while (!(cin >> Array[i]))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "������ �����. ����������, ��������� �������.\n";
			cout << "������� ����� �����.\n";
		}
		cin.clear();
		while (cin.get() != '\n');
		system("cls");
	}

	int min = Array[0];
	int min2;
	int index = 0;

	// ����� ����������� ��������
	for (int i(1); i < n; i++)
	{
		if (min >= Array[i])
		{
			min2 = min;
			min = Array[i];
			index = i;
		}
	..
	.............................................................................................................................................................................................................................................................................................................................................................................................................................................................................
	

	// �������� �� ����������� ���������� ������ ����������� ��������� � �������
	if (min == min2)
	{
		char qrt;
		cout << "� ������� ���� ��������, �������� ������� ����� �������� ������������ ��������.\n"
			<< "��������� ������ ��������� ����� ���� ������������. ���������� ������ ���������? (y/n)";
		while (!(cin >> qrt) || (qrt != 'y' && qrt != 'n'))
		{
			system("cls");
			cin.clear();
			while (cin.get() != '\n');
			cout << "� ������� ���� ��������, �������� ������� ����� �������� ������������ ��������.\n"
				<< "��������� ������ ��������� ����� ���� ������������. ���������� ������ ���������? (y/n)";

		}
		if (qrt == 'n') return 0;
		system("cls");
	}

	// ����� 
	cout << "�������� ������: ";
	for (int i(0); i < n; i++)
	{
		cout << Array[i] << " ";
	}
	cout << "\n���������� ������� �������: " << min;
	cout << "\n������ ����������� ��������: " << index << endl;
	++index;
	int count = n - index;
	cout << "\n���������� ���������, ����������� ����� ����������� ��������: " << count << endl;
	system("pause");
	return 0;
}


// 2. � �������� 2-������ ������� (� = 3�3) �������� ������� 
// ������, ���������� ����������� � ������������ ������� �������
#include <iostream>
#include "conio.h"
using namespace std;
int main()
{
	const int n = 3;
	int Array[n][n];
	setlocale(LC_ALL, "Russian");
	// ���� �������
	cout << "��������� ������ ������ �������.\n";
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
		{
			cout << "[" << i + 1 << "][" << j + 1 << "]: ";
			while (!(cin >> Array[i][j]))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "������ �����. ����������, ��������� �������.\n";
				cout << "������� ����� �����.\n";
			}
			cin.clear();
			while (cin.get() != '\n');
			system("cls");
		}
	}
	int min = Array[0][0];
	int max = Array[0][0];
	int min1 = NULL;
	int max1 = NULL;
	int indexMin = 0;
	int indexMax = 0;
	int j = 1;
	// ����� ������������ � ������������� ��������� ������� � �� ����� ������
	for (int i(0); i < n; i++)
	{
		for (; j < n; j++)
		{
			if (min >= Array[i][j])
			{
				min1 = min;
				min = Array[i][j];
				indexMin = i;
			}
			if (max <= Array[i][j])
			{
				max1 = max;
				max = Array[i][j];
				indexMax = i;
			}
		}
		j = 0;
	}
	// �������� �� ����������� ���������� ������ �����������/������������ ��������� � �������
	if (max1 == max || min1 == min)
	{
		char qrt;
		cout << "� ������� ���� ��������, �������� ������� ����� �������� �������������/������������ ��������.\n"
			<< "��������� ������ ��������� ����� ���� ������������. ���������� ������ ���������? (y/n)";
		while (!(cin >> qrt) || (qrt != 'y' && qrt != 'n'))
		{
			system("cls");
			cin.clear();
			while (cin.get() != '\n');
			cout << "� ������� ���� ��������, �������� ������� ����� �������� �������������/������������ ��������.\n"
				<< "��������� ������ ��������� ����� ���� ������������. ���������� ������ ���������? (y/n)";

		}
		if (qrt == 'n') return 0;
		system("cls");
	}
	// ����� �������
	cout << "�������� ������:\n";
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
		{
			cout << Array[i][j] << " ";
		}
		cout << endl;
	}
	// ����� ������� ������ ���������� ����������� � ������������ ������� �������
	int a;
	for (int j(0); j < n; j++)
	{
		a = Array[indexMax][j];
		Array[indexMax][j] = Array[indexMin][j];
		Array[indexMin][j] = a;
	}
	// ����� ����������
	cout << "\n���������� ������� �������: " << min << endl;
	cout << "���������� ������� �������: " << max << endl;

	cout << "\n���������� ������:\n";
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
			cout << Array[i][j] << " ";
		cout << endl;
	}
	system("pause");
}



#include <iostream>
using namespace std;
void input(int *Array, int n);
void output(int *Array, int n);
void sortArray(int *Array, int n);
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

	int *A;
	A = new int[n];
	system("cls");
	cout << "��������� �������.\n";
	input(A, n);
	system("cls");
	cout << "��������� ������: "; output(A, n); cout << endl;
	sortArray(A, n);
	cout << "������, ��������������� �� �����������: ";  output(A, n); cout << endl;
	delete[] A;
	system("pause");
	return 0;
}

void input(int *Array, int n)
{
	for (int i(0); i < n; i++)
	{
		cout << "������� ��������  �������� [" << i + 1 << "]: ";
		while (!(cin >> *(Array + i)))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "��������� ������." << endl;
			cout << "������� ��������  �������� [" << i + 1 << "]: ";
		}
		cin.clear();
		while (cin.get() != '\n');
	}
}
void output(int *Array, int n)
{
	for (int i(0); i < n; i++)
	{
		cout << *(Array + i) << " ";
	}
}
void sortArray(int *Array, int n)
{
	int a;
	for (int k(0); k <= n; k++)
	{
		for (int i(0); i < n - 1; i++)
		{
			if (*(Array + i) > *(Array + i + 1))
			{
				a = *(Array + i);
				*(Array + i) = *(Array + i + 1);
				*(Array + i + 1) = a;
			}
		}
	}
}

//Zadacha dlya pervo kursnitse
#include <iostream>
using namespace std;
int main()
{
	const int n = 400;
	int msv[50];
	int f = 100;
	for (int i = 0; i < n; i++) {
		msv[i] = f++;
	}
	cout << "Prostie 4isla: ";
	for (int i = 0; i < n; i++)
	{
		for (int j = 2; j <= sqrt(msv[i]); j++)
		{
			if (msv[i] % j == 0 && msv[i] != j)
			{
				msv[i] = 0;
				break;
			}
		}
		if (msv[i] != 0)
		{
			cout << msv[i] << " ";
		}
	}
	system("pause");
	return 0;
}