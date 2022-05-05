#include "unit.h"
#include "List.h"
#include <iostream>
#include <locale>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int value = 0; //переменные размера стека и вводимых данных
	int flag = 1, c;
	int list_size;
	///////////////////////////////////////////////////////ЗАДАНИЕ №1
	cout << "Унарные операции с целыми числами\n";
	unit Int;
	cout << "Введите целое число: " << endl;

	while (true)
	{
		cin >> value;

		if (cin.get() != '.')
		{
			break;
		}
		else cout << "Число не целое!\n";
		cin >> value;
	}
	

	Int.setData(value);
	
	while (flag == 1)
	{
		cout << "Выберите, какие операции провести с числом:" << endl;
		cout << "2 - протестировать оператор префиксного инкремента" << endl;
		cout << "3 - протестировать оператор постфиксного инкремента" << endl;
		cout << "4 - протестировать оператор префиксного декремента" << endl;
		cout << "5 - протестировать оператор постфиксного декремента" << endl;
		cout << "0 - Переход ко втрому заданию работы" << endl;
		cout << "--> ";
		cin >> c;
		switch (c)
		{
		case 1:
			system("cls");
			cout << "Введите значение целого числа" << endl;
			cin >> value;
			Int.setData(value);
			cout << "Объект класса unit создан" << endl;
			break;
		case 2:
			system("cls");
			cout << "Значение числа до операции: ";
			Int.print();
			cout << endl;
			Int = ++Int;
			
				cout << "Значение числа теперь: ";
			Int.print();
			break;
		case 3:
			system("cls");
			cout << "Значение числа до операции: ";
			Int.print();
			cout << endl;
			Int = Int++;
			cout << "Значение числа теперь: ";
			Int.print();
			break;
		case 4:
			system("cls");
			cout << "Значение числа до операции: ";
			Int.print();
			cout << endl;
			--Int;
			cout << "Значение числа теперь: ";
			Int.print();
			break;
		case 5:
			system("cls");
			cout << "Значение числа до операции: ";
			Int.print();
			cout << endl;
			Int = Int--;
			cout << "Значение числа теперь: ";
			Int.print();
			break;
		case 0: //0 - Выход
			cout << "\n";
			flag = 0;
			break;
		}
	}
	
	//№2
	system("cls");
	int num, l, r;
	List list;
	List* buffer;
	cout << "Задание №2 - Бинарные операторы\n" << endl;
	flag = 1;
	cout << "Введите размер списка:";
	cin >> list_size;
	system("cls");
	
	
	for (int i = 0; i < list_size; i++)
	{
		list.push (rand() % (35 - 5 + 1) + 5);
	}
	while (flag == 1)
	{
		cout << "Выберите, какие операции провести со списком:" << endl;
		cout << "1 - Добавление нового элемента в список" << endl;
		cout << "2 - Удаление элемента из списка" << endl;
		cout << "3 - Вывод списка на экран" << endl;
		cout << "4 - Оператор сравнения \"<\"" << endl;
		cout << "5 - Оператор сравнения \">\"" << endl;
		cout << "6 - Оператор сравнения \"==\"" << endl;
		cout << "7 - Оператор сравнения \"!=\"" << endl;
		cout << "8 - Оператор сравнения \"<=\"" << endl;
		cout << "9 - Оператор сравнения \">=\"" << endl;
		cout << "10 - Возвращение подсписка по двум индексам \"()\"" << endl;
		cout << "--> ";
		cin >> c;
		switch (c)
		{
		case 1:
			system("cls");
			cout << "Введите значение: " << endl;
			cin >> value;
			list.push(value);
			cout << "Значение добавлено в стек\n " << endl;
			break;
		case 2:
			system("cls");
			cout << "Введите номер элемента, который вы хотите удалить: ";
			cin >> num;
			if (num < 0 || num >= list.get_size())
				cout << "Номер элемента введен некорректно.";
			else
				list.del(num);
			break;
		case 3:
			system("cls");
			if (list.get_size() == 0)
			{
				cout << "Стек пуст, выводить нечего.\n" << endl;
				break;
			}
			else
			{
				system("cls");
				list.print();
				cout << "\n";
			}
			break;
		case 4:
			system("cls");
			cout << "Введите число, с которым хотите провести сравнение каждого элемента списка, путем применения оператора \"<\": ";
			cin >> value;
			value < list;
			break;
		case 5:
			system("cls");
			
				cout << "Введите число, с которым хотите провести сравнение каждого элемента списка, путем применения оператора \">\": ";
			cin >> value;
			value > list;
			break;
		case 6:
			system("cls");
			cout << "Введите число, с которым хотите провести сравнение каждого элемента списка, путем применения оператора \"==\": ";
			cin >> value;
			value == list;
			break;
		case 7:
			system("cls");
			cout << "Введите число, с которым хотите провести сравнение каждого элемента списка, путем применения оператора \"!=\": ";
			cin >> value;
			value != list;
			break;
		case 8:
			system("cls");
			cout << "Введите число, с которым хотите провести сравнение каждого элемента списка, путем применения оператора \"<=\": ";
			cin >> value;
			value <= list;
			break;
		case 9:
			system("cls");
			cout << "Введите число, с которым хотите провести сравнение каждого элемента списка, путем применения оператора \">=\": ";
			cin >> value;
			value >= list;
			break;
		case 10:
			system("cls");
			cout << "Введите индексы(границы) подсписка: ";
			cin >> l >> r;
			buffer = list(l, r);
			buffer->print();
			break;
		case 0:
			cout << "\n";
			flag = 0;
			break;
		}
	}
	return 0;
}
