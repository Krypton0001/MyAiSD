#include <iostream>
#include <conio.h>
#define ESC 27
using namespace std;

struct Queue {
	int item;
	Queue *next;
};
Queue *pbeg, *pend;

//Создание Стек и добавление элементов
void first(int &a);
//Добавление элементов
void add();
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

void main()
{
	pbeg = NULL;
	pend = NULL;
	setlocale(LC_ALL, "ru");
	int Q;
	cout << "\t\t\tВыход из программ 'ESC'\n\n";
	do
	{
		cout << "\n1 -> Добавление первого элементов\n2 -> Добавление элементов\n3 -> Вывод на экран\n" <<
	"4 -> Поиск элемента по позицию\n5 -> Поиск элемента по значению\n6 -> Удаление элемента из очередьди\n7 -> Уничтожение  очереди\n";
		char q;	q = _getch(); system("cls");
		switch (q) {
		case'1':first(Q);    break;
		case'2':add();       break;
		case'3':show(); counter(Q); break;
		case'4':searchPos(); break;
		case'5':searchVal(); break;
		case'6':rel(Q);      break;
		case'7':pop(Q);      break;
		case ESC:exit(0);    break;
		default: {cout << "Введите доступные значение!!! \n\n"; }
		}
	} while (true);
}

void first(int &a)
{
	cout << "Вводите элементы в очередь: ";
	cin >> a;
	Queue *pv = new Queue;
	pv->item = a;
	pv->next = NULL;
	pbeg = pv;
	pend = pv;
}

void add()
{
	cout << "Вводите элементы в очередь: ";
	int a;
	Queue *pv = new Queue;
	cin >> a;
	pv->item = a;
	pv->next = NULL;	
	if (pbeg != 0)
	{
		pend->next = pv;
		pend = pv;
	}
}

void show()
{
	Queue *pv = new Queue;
	pv = pend;
	pv = pbeg;
	if (pv == 0)
	{
		cout << "Очередь пуст!!! ";
	}
	else
	{
		cout << "Элементы в очередье: ";
		while (pv != 0)
		{
			cout << " [ " << pv->item << " ]: ";
			pv = pv->next;
		}
	}
	cout << "\n";
}

void counter(int &count)
{
	Queue *pv = new Queue;
	count = 0;
	pv = pbeg;
	while (pv != 0)
	{
		pv->item;
		pv = pv->next;
		count++;
	}
	cout << "\nКоличество элементов в очереди: [ " << count << " ]: \n";
	delete pv;
}

void searchPos()
{
	Queue *pv = new Queue;
	cout << "Поиска элемента по порядковому номеру: ";
	pv = pbeg;
	int a, i = 0;
	if (pv == 0)
	{
		cout << "Очередь пуст!!!\n\n";
	}
	else
	{
		cin >> a;
		while (pv != 0)
		{
			i++;
			if (a == i)
			{
				cout << "Элемент по позицию найдено :-) " << pv->item << "\n\n";
			}
			pv = pv->next;
		}
	}
}

void searchVal()
{
	Queue *pv = new Queue;
	int a, count = 0;
	cout << "Поиска значения элемента по заданному: ";
	pv = pbeg;
	if (pv == 0)
	{
		cout << "Очередь пуст!!!\n\n";
	}
	else
	{
		cin >> a;
		while (pv != 0)
		{
			count++;
			if (a == pv->item)
			{
				cout << "Элемент найдено :-) " << a << endl; break;
			}
			pv = pv->next;
		}
	}
}

void rel(int &count)
{
	Queue *pv = new Queue;
	pv = pbeg;
	int a;
	if (pv == 0)
	{
		cout << "Очередь пуст!!!\n\n";
	}
	else
	{
		a = pv->item;
		pv = pbeg;
		pbeg = pbeg->next;
		count--;
		cout << "Удаляемый элемент: " << a << endl;
	}
	delete pv;
}

void pop(int &count)
{
	if (pbeg == 0)
	{
		cout << "Очередь пуст!!!\n\n";
	}
	else
	{
		cout << "Все элементы успешно удалены :-) \n\n";
		while (pbeg != 0)
		{
			Queue *pv = new Queue;
			pv = pbeg;
			pbeg = pbeg->next;
			delete pv;
			count--;
		}
		count = 0;
		pbeg = NULL;
		pend = NULL;
	}
}