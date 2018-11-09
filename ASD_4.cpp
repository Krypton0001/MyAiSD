#include <iostream>
#include <conio.h>
#define ESC 27
using namespace std;
struct Stack {
	int item;
	Stack*next;
};
Stack*top;
Stack*pv;
//Создание Стек и добавление элементов
Stack *first();
//Показывание элементов в стек
void show();
//Удаление элементов в стеке
void rel(int &count);
//Разрушение стека
void pop(int &count);
//Считование кол-о элементов в стеке
void counter(int &count);
//Нахождение элементы по позицию
void searchPos();
//Нахождение элементы по значению
void searchVal();
//Нахождение макс и мин элементов в сетке
void Max();
//Нахождение макс и мин элементов в сетке
void Min();

void main()
{	
	setlocale(LC_ALL, "ru");
	int count;
	cout << "\t\t\tВыход из программ 'ESC'\n\n";
	do
	{
		cout << "\n1 -> Добавление элементов в стек\n2 -> Вывод на экран\n3 -> Удаление элемента из стека\n4 -> Разрушение  стека\n5 -> Поиск элемента по позицию\n" <<
			"6 -> Поиск элемента по значению\n";
		char q;	q = _getch(); system("cls");
		switch (q) {
		case'1':top = first(); break;
		case'2':show(); counter(count);  Max(); Min(); break;
		case'3':rel(count);    break;
		case'4':pop(count);    break;
		case'5':searchPos();   break;
		case'6':searchVal();   break;
		case ESC:exit(0);      break;
		default: {cout << "Введите доступные значение!!! \n"; }
		}
	} while (true);
}
Stack*first() {
	int a;
	cout << "Вводите элементы стека: ";
	cin >> a;
	cin.get();
		Stack*pv = new Stack;
		pv->item = a;
		pv->next = top;
	return pv;
}
void show() {
	Stack*pv = new Stack;
	pv = top;
	if (top == 0) {
		cout << "Стек пуст!!! \n\n";
	}
	else {
		cout << "Элементы в стеке: ";
		while (pv != 0) {
			cout << "[ " << pv->item << " ] ";
			pv = pv->next;
		}
		cout << "\n\n";
	}
}
void pop(int &count) {
	Stack *pv = new Stack;
	if (top == 0) {
		cout << "Стек пуст!!! \n\n";
	}
	else {
		while (top != 0) {
			Stack*pv = top;
			top = top->next;
			delete pv;
			count--;
		}
		cout << "Элементы удалены: \n\n";	
	}
	delete pv;
}	

void rel(int &count) {
	Stack *pv = new Stack;
	int a;
	if (top == 0) {
		cout << "Стек пуст!!! \n\n";
	}
	else {
		pv = top;
		top = top->next;
		count--;
	}
	delete pv;
}

void counter(int &count) {
	Stack *pv = new Stack;
	 count = 0;
	pv = top;
	while (pv != 0) {
		pv->item;
		pv = pv->next;
		count++;
	}
	cout << "Количества элементов в стеке = [ " << count << " ]\n\n";
	delete pv;
}

void Max() {
	int max;
	Stack *pv = new Stack;
	pv = top;
	max = pv->item;
	if (top == 0) {
		cout << "Стек пуст!!! \n\n";
	}
	else {
		while (pv != 0) {
			if (max < pv->item) { max = pv->item; }
			pv = pv->next;
		}
	}
	cout << "Макс элемент [ " << max << " ]:  ";
}
void Min() {
	int min;
	min = top->item;
	Stack *pv = new Stack;
	pv = top;
	if (top == 0) {
		cout << "Стек пуст!!! \n\n";
	}
	else {
		while (pv != 0) {
			if (min > pv->item) { min = pv->item; }
			pv = pv->next;
		}
	}
	cout << "Мин элемент [ " << min << " ]:\n\n";
}
void searchPos() {
	cout << "Поиска элемента по порядковому номеру: ";
	Stack *pv = new Stack;
	int a, i = 0;
	pv = top;
	if (top == 0) {
		cout << "\nСтек пуст!!!\n" << endl;
	}
	else {
		cin >> a;
		while(pv != 0) {
			i++;
			if (a == i) {
				cout << "Элемент по позицию найдено :-) "  << pv->item << "\n\n";
			}
			pv = pv->next;
		}
	}
}

void searchVal() {
	cout << "Поиска значения элемента по заданному: ";
	Stack *pv = new Stack;
	pv = top;
	int count = 0, a;
	if (top == 0) {
		cout << "\nСтек пуст!!!\n\n";
	}
	else {
		cin >> a;
		while (pv != 0) {
			count++;
			if (a == pv->item) {
				cout << "Элемент найдено :-) " << a << endl;
			}
			pv = pv->next;
		}
		cout << "Элементы не найдено :-( \n\n";
	}
}	