
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
using namespace std;

struct List
{
	int *element;
	int last;
	int lght;
	bool sort;
};

// валидация ввода
void inputYN(char &q);
void inputNumb(int &n, const string &str);
void inputNumb(int &n, int minN, const string &str);
void inputNumb(int &n, int minN, int maxN, const string &str);
// создание списка
void newList(List &L);
// вывод главного меню
void menu(List &L);
// вывод списка
void output_list(List &L);
// добавление элементов
void input_elemList(List &L);
void insert_pos(List &L, int &pos, int val);
// удаление элементов списка
void delete_elemList(List &L);
void delete_pos(List &L, int pos);
void delete_val(List &L, int val);
// сортировка списка
void sort_list(List &L);
void sort(List &L);
// поиск элементов в списке
void search_elemList(List &L);
int search_pos(List &L, int pos);
void search_val(List &L, int val);
// удаление списка
void delete_List(List &L);

int main()
{
	List L;
	setlocale(LC_ALL, "Russian");
	newList(L);
	system("cls");
	menu(L);
	delete_List(L);
	return 0;
}

// валидация ввода
void inputYN(char &q)
{
	do { q = _getch(); } while (q != 'y' && q != 'n');
}
void inputNumb(int &n, const string &str)
{
	cout << str;
	while (!(cin >> n))
	{
		system("cls");
		cin.clear();
		while (cin.get() != '\n');
		cout << "Oшибка ввода данных. Пожалуйста, убедитесь, что было введено допустимое значение.\n";
		cout << str;
	}
	cin.clear();
	while (cin.get() != '\n');
}
void inputNumb(int &n, int minN, const string &str)
{
	cout << str;
	while (!(cin >> n) || n < minN)
	{
		system("cls");
		cin.clear();
		while (cin.get() != '\n');
		cout << "Oшибка ввода данных. Пожалуйста, убедитесь, что было введено допустимое значение.\n";
		cout << str;
	}
	cin.clear();
	while (cin.get() != '\n');
}
void inputNumb(int &n, int minN, int maxN, const string &str)
{
	cout << str;
	while (!(cin >> n) || n < minN || n > maxN)
	{
		system("cls");
		cin.clear();
		while (cin.get() != '\n');
		cout << "Oшибка ввода данных. Пожалуйста, убедитесь, что было введено допустимое значение.\n";
		cout << str;
	}
	cin.clear();
	while (cin.get() != '\n');
}

// создание списка
void newList(List &L)
{
	string str = "Введите значение максимально допустимого количества элементов в списке.\n";
	inputNumb(L.lght, 1, str);
	L.element = new int[L.lght];

	for (int i(0); i < L.lght; i++)
	{
		L.element[i] = INT_MIN;
	}

	L.last = -1;
	L.sort = false;
}

// вывод главного меню
void menu(List &L)
{
	do
	{
		system("cls");
		string buff;
		ifstream in("D:\Menu.txt");
		while (getline(in, buff))
		{
			cout << buff << endl;
		}

		char q; q = _getch();
		switch (q)
		{
		case '1': { output_list(L);		break; }
		case '2': { input_elemList(L);  break; }
		case '3': { delete_elemList(L); break; }
		case '4': { search_elemList(L); break; }
		case '5': { sort_list(L);		break; }
		case  27: { return; }
		}

	} while (true);
}

// вывод списка
void output_list(List &L)
{
	system("cls");
	char q;
	if (L.last == -1)
	{
		cout << "Список пуст.\nХотите добавить элементы в список?(y/n) ";
		inputYN(q);
		if (q == 'y')
		{
			input_elemList(L);
		}
		else
		{
			return;
		}
	}

	cout << "Элементы списка ([позиция]:значение).\n";
	for (int i(0); (L.element[i] != INT_MIN) && (i != L.lght); i++)
	{
		cout << "[" << i + 1 << "]:" << L.element[i] << " ";
	}
	cout << endl;

	if (L.last == L.lght - 1)
	{
		cout << "\nСписок полон. Хотите удалить элементы?(y/n)";
		inputYN(q);
		if (q == 'y') delete_elemList(L);
		return;
	}
	cout << "\nКоличество элементов: " << L.last + 1;
	cout << "\nВозможно добавить еще " << L.lght - (L.last + 1) << " элементов." << endl;

	do { q = _getch(); } while (q != 8);
}

// добавление элементов
// меню добавления элементов
void input_elemList(List &L)
{
	system("cls");
	char q;
	int countElem;
	int n = L.lght - (L.last + 1);
	if (L.last == L.lght - 1)
	{
		cout << "\nСписок полон. Хотите удалить элементы?(y/n)";
		inputYN(q);
		if (q == 'y')
		{
			delete_elemList(L);
		}
		return;
	}

	system("cls");
	string str = "Возможно добавить " + to_string(n) + " элементов.\nСколько элементов хотите добавить?\n";
	inputNumb(countElem, 1, n, str);

	system("cls");
	string buff;
	ifstream in("D:\insertMenu.txt");
	while (getline(in, buff))
	{
		cout << buff << endl;
	}

	while (true)
	{
		q = _getch();
		if (q == '1' || q == '2' || q == '3')
		{
			system("cls");
			int val;
			int pos;
			string str2;
			switch (q)
			{
			case '1':
			{
				system("cls");
				str = "Добавление элемента в начало списка.";
				pos = 0; break;
			}

			case '2':
			{
				system("cls");
				str = "Добавление элемента в конец списка.";
				pos = L.last + 1; break;
			}

			case '3':
			{
				system("cls");
				str = "Добавление элемента по позиции.\n";
				for (int i(0); i < countElem; i++)
				{
					str2 = str + "(" + to_string(i + 1) + ") Введите позицию нового элемента(целое число в диапазоне от 1 до " + to_string(L.last + 2) + ")\n";
					inputNumb(pos, 1, L.last + 2, str2); --pos;
					str2 = "Введите целочисленное значение нового элемента.\n";
					inputNumb(val, str2);
					insert_pos(L, pos, val);
					L.sort = false;
					system("cls");

				}
				return;
			}
			}

			for (int i(0); i < countElem; i++)
			{
				str2 = "(" + to_string(i + 1) + ") " + str + "\nВведите целочисленное значение нового элемента.\n";
				inputNumb(val, str2);
				insert_pos(L, pos, val);
				L.sort = false;
				system("cls");

			}
			return;
		}
		else if (q == 8)
		{
			cout << "\nХотите вернуться в главное меню?(y/n)";
			inputYN(q);
			if (q == 'y')
			{
				return;
			}
			else
			{
				system("cls");
				string buff;
				ifstream in("D:\insertMenu.txt");
				while (getline(in, buff))
				{
					cout << buff << endl;
				}
			}
		}
	}
}
// добавление по позиции
void insert_pos(List &L, int &pos, int val)
{
	L.last++;
	if (pos == L.last)
	{
		L.element[pos] = val;
		pos++;
	}

	else
	{
		for (int i(L.last); i > pos; i--)
		{
			L.element[i] = L.element[i - 1];
		}
		L.element[pos] = val;
	}
}

// удаление элементов списка
// меню удаления элементов
void delete_elemList(List &L)
{
	system("cls");
	char q;

	if (L.last == -1)
	{
		cout << "Список пуст.\nХотите добавить элементы в список?(y/n)";
		inputYN(q);
		if (q == 'y')
		{
			input_elemList(L);
		}
		return;
	}

	system("cls");
	int countElem;
	string str = "Возможно удалить " + to_string(L.last + 1) + " элементов.\nСколько элементов хотите удалить?\n";
	inputNumb(countElem, 1, L.last + 1, str);

	while (true)
	{
		system("cls");
		string buff;
		ifstream in("D:\deleteMenu.txt");
		while (getline(in, buff))
		{
			cout << buff << endl;
		}

		q = _getch();
		if (q == 8)
		{
			cout << "\nХотите вернуться в главное меню?(y/n)";
			inputYN(q);
			if (q == 'y') return;
		}

		switch (q)
		{
		case '1':
		{
			system("cls");
			for (int i(0); i < countElem; i++)
			{
				delete_pos(L, 0);
			}

			cout << "Элементы удалены.";
			_getch(); return;
		}

		case '2':
		{
			system("cls");
			for (int i(0); i < countElem; i++)
			{
				delete_pos(L, L.last);
			}

			cout << "Элементы удалены.";
			_getch(); return;
		}

		case '3':
		{
			system("cls");
			int pos;

			for (int i(0); i < countElem; i++)
			{
				str = "(" + to_string(i + 1) + "). Введите позицию удаляемого элемента(целое число в диапазоне от 1 до " + to_string(L.last + 1) + ")\n";
				inputNumb(pos, 1, L.last + 1, str); --pos;
				delete_pos(L, pos);
				system("cls");
			}

			cout << "Элементы удалены.";
			_getch(); return;
		}
		case '4':
		{
			system("cls");
			int val;

			for (int i(0); i < countElem; i++)
			{
				str = "(" + to_string(i + 1) + "). Введите целочисленное значение удаляемого элемента.\n";
				inputNumb(val, str);
				delete_val(L, val);
				_getch();
				system("cls");
			}

			return;
		}
		}
	}
}
// удаление по позиции
void delete_pos(List &L, int pos)
{
	for (int i(0); i <= L.last; i++)
	{
		if (i == pos)
		{
			for (; i < L.last; i++)
			{
				L.element[i] = L.element[i + 1];
			}
			}
			L.element[i] = INT_MIN;
			--L.last; return;
		}
	}
}
//удаление по значению
void delete_val(List &L, int val)
{
	char q;
	int pos;
	int countElem = 0;

	for (int i(0); i <= L.last; i++)
	{
		if (L.element[i] == val)
		{
			countElem++; pos = i;
		}
	}

	if (countElem == L.last + 1)
	{
		cout << "Все элементы списка равны зананному значению. Удалить их все?(y/n)" << endl;
		inputYN(q);

		if (q == 'y')
		{
			for (int i(0); i <= L.last; i++)
			{
				L.element[i] = INT_MIN;
			}

			L.last = -1;
			cout << "\nЭлементы удалены.";
		}

		return;
	}

	if (countElem == 0)
	{
		cout << "Заданного элемента в списке нет.\n"; return;
	}

	if (countElem == 1)
	{
		delete_pos(L, pos);
		cout << "\nЭлемент удален.";
		return;
	}

	else
	{
		cout << "Список содержит несколько элементов, значение которых равно заданному." << endl;
		int j = 0;
		for (int i(0); i <= L.last; i++)
		{
			if (val == L.element[i])
			{
				cout << "(" << ++j << ")[" << i + 1 << "]:" << L.element[i] << "  ";
			}
		}

		string str = "\nВведите номер элемента, который хотите удалить.\n";
		int pos;
		inputNumb(pos, 1, j, str);
		j = 1;
		for (int i(0); i <= L.last; i++)
		{
			if (val == L.element[i])
			{
				if (j == pos)
				{
					pos = i; break;
				}
				j++;
			}
		}

		delete_pos(L, pos);
		cout << "\nЭлементы удалены.";
		return;
	}
}

// сортировка списка
//меню сортироки
void sort_list(List &L)
{
	system("cls");
	char q;
	if (L.last == -1)
	{
		cout << "Список пуст.\nХотите добавить элементы в список?(y/n) ";
		inputYN(q);
		if (q == 'y')
		{
			input_elemList(L);
		}
		return;
	}

	if (!L.sort)
	{
		cout << "Вы уверены, что хотите отсортировать список?(y/n)";
		inputYN(q);
		if (q == 'n')
		{
			return;
		}
		sort(L);
		L.sort = true;
		cout << endl;
	}

	cout << "Список отсортирован.";
	do q = _getch(); while (q != 8);
}
// сортирока
void sort(List &L)
{
	int a;
	L.sort = true;
	for (int j(0); j < L.last + 1; j++)
	{
		for (int i(0); i < L.last; i++)
		{
			if (L.element[i] > L.element[i + 1])
			{
				a = L.element[i];
				L.element[i] = L.element[i + 1];
				L.element[i + 1] = a;
			}
		}
	}
}

// поиск элементов в списке
// меню поиска
void search_elemList(List &L)
{
	system("cls");
	char q;

	// если список пуст
	if (L.last == -1)
	{
		cout << "Список пуст.\nХотите добавить элементы в список?(y/n) ";
		inputYN(q);
		if (q == 'y')
		{
			input_elemList(L);
		}
		return;
	}

	string str;
	cout << "\tПоиск элемента в списке.\n\n";
	cout << "1 - по позиции\n2 - по значению\n";
	while (true)
	{
		q = _getch();
		switch (q)
		{
			// поиск по позиции
		case '1':
		{
			system("cls");
			int pos;
			str = "Введите позицию элемента(целое число в диапазоне от 1 до " + to_string(L.last + 1) + ")\n";
			inputNumb(pos, 1, L.last + 1, str);

			system("cls");
			cout << "Результат поиска по позиции - [" << pos << "]:" << search_pos(L, pos - 1) << endl;
			break;
		}

		// поиск по значению
		case '2':
		{
			int val;
			system("cls");
			str = "Введите значение элемента.\n";
			inputNumb(val, str);
			search_val(L, val);
			break;
		}
		// выход в главное меню
		case 8:
		{
			cout << "\nХотите вернуться в главное меню?(y/n)";
			inputYN(q);
			if (q == 'y')
			{
				return;
			}
		}
		}
	}
}
// поиск по значению
void search_val(List &L, int val)
{
	int pos;
	int countElem = 0;
	// подсчет количества элементов в списке, равных заданному значению
	for (int i(0); i <= L.last; i++)
	{
		if (val == L.element[i])
		{
			countElem++;
			pos = i;
		}
	}
	// вывод результатов
	if (countElem == L.last + 1)
	{
		cout << "Все элементы списка равны заданному значению." << endl;
	}
	else if (countElem == 1)
	{
		cout << "Результат поиска по значению - [" << pos + 1 << "]:" << search_pos(L, pos) << endl;
	}
	else if (countElem == 0)
	{
		cout << "Запрашиваемый элемент не найден" << endl;
	}
	else
	{
		cout << "В списке найдено несколько элементов, значение которых равно заданному значению. " << endl;
		for (int i(0); i <= L.last; i++)
		{
			if (val == L.element[i])
			{
				cout << "[" << i + 1 << "]:" << L.element[i] << "  ";
			}
		}
	}
}
// поиск по позиции
int search_pos(List &L, int pos)
{
	for (int i(0); i <= L.last; i++)
	{
		if (i == pos)
		{
			return L.element[i];
		}
	}
}

// удаление списка (освобождение памяти)
void delete_List(List &L)
{
	delete[] L.element;
	L.element = NULL;
}
