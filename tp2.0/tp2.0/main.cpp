#include "unit.h"
#include "List.h"
#include <iostream>
#include <locale>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int value = 0; //���������� ������� ����� � �������� ������
	int flag = 1, c;
	int list_size;
	///////////////////////////////////////////////////////������� �1
	cout << "������� �������� � ������ �������\n";
	unit Int;
	cout << "������� ����� �����: " << endl;

	while (true)
	{
		cin >> value;

		if (cin.get() != '.')
		{
			break;
		}
		else cout << "����� �� �����!\n";
		cin >> value;
	}
	

	Int.setData(value);
	
	while (flag == 1)
	{
		cout << "��������, ����� �������� �������� � ������:" << endl;
		cout << "2 - �������������� �������� ����������� ����������" << endl;
		cout << "3 - �������������� �������� ������������ ����������" << endl;
		cout << "4 - �������������� �������� ����������� ����������" << endl;
		cout << "5 - �������������� �������� ������������ ����������" << endl;
		cout << "0 - ������� �� ������ ������� ������" << endl;
		cout << "--> ";
		cin >> c;
		switch (c)
		{
		case 1:
			system("cls");
			cout << "������� �������� ������ �����" << endl;
			cin >> value;
			Int.setData(value);
			cout << "������ ������ unit ������" << endl;
			break;
		case 2:
			system("cls");
			cout << "�������� ����� �� ��������: ";
			Int.print();
			cout << endl;
			Int = ++Int;
			
				cout << "�������� ����� ������: ";
			Int.print();
			break;
		case 3:
			system("cls");
			cout << "�������� ����� �� ��������: ";
			Int.print();
			cout << endl;
			Int = Int++;
			cout << "�������� ����� ������: ";
			Int.print();
			break;
		case 4:
			system("cls");
			cout << "�������� ����� �� ��������: ";
			Int.print();
			cout << endl;
			--Int;
			cout << "�������� ����� ������: ";
			Int.print();
			break;
		case 5:
			system("cls");
			cout << "�������� ����� �� ��������: ";
			Int.print();
			cout << endl;
			Int = Int--;
			cout << "�������� ����� ������: ";
			Int.print();
			break;
		case 0: //0 - �����
			cout << "\n";
			flag = 0;
			break;
		}
	}
	
	//�2
	system("cls");
	int num, l, r;
	List list;
	List* buffer;
	cout << "������� �2 - �������� ���������\n" << endl;
	flag = 1;
	cout << "������� ������ ������:";
	cin >> list_size;
	system("cls");
	
	
	for (int i = 0; i < list_size; i++)
	{
		list.push (rand() % (35 - 5 + 1) + 5);
	}
	while (flag == 1)
	{
		cout << "��������, ����� �������� �������� �� �������:" << endl;
		cout << "1 - ���������� ������ �������� � ������" << endl;
		cout << "2 - �������� �������� �� ������" << endl;
		cout << "3 - ����� ������ �� �����" << endl;
		cout << "4 - �������� ��������� \"<\"" << endl;
		cout << "5 - �������� ��������� \">\"" << endl;
		cout << "6 - �������� ��������� \"==\"" << endl;
		cout << "7 - �������� ��������� \"!=\"" << endl;
		cout << "8 - �������� ��������� \"<=\"" << endl;
		cout << "9 - �������� ��������� \">=\"" << endl;
		cout << "10 - ����������� ��������� �� ���� �������� \"()\"" << endl;
		cout << "--> ";
		cin >> c;
		switch (c)
		{
		case 1:
			system("cls");
			cout << "������� ��������: " << endl;
			cin >> value;
			list.push(value);
			cout << "�������� ��������� � ����\n " << endl;
			break;
		case 2:
			system("cls");
			cout << "������� ����� ��������, ������� �� ������ �������: ";
			cin >> num;
			if (num < 0 || num >= list.get_size())
				cout << "����� �������� ������ �����������.";
			else
				list.del(num);
			break;
		case 3:
			system("cls");
			if (list.get_size() == 0)
			{
				cout << "���� ����, �������� ������.\n" << endl;
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
			cout << "������� �����, � ������� ������ �������� ��������� ������� �������� ������, ����� ���������� ��������� \"<\": ";
			cin >> value;
			value < list;
			break;
		case 5:
			system("cls");
			
				cout << "������� �����, � ������� ������ �������� ��������� ������� �������� ������, ����� ���������� ��������� \">\": ";
			cin >> value;
			value > list;
			break;
		case 6:
			system("cls");
			cout << "������� �����, � ������� ������ �������� ��������� ������� �������� ������, ����� ���������� ��������� \"==\": ";
			cin >> value;
			value == list;
			break;
		case 7:
			system("cls");
			cout << "������� �����, � ������� ������ �������� ��������� ������� �������� ������, ����� ���������� ��������� \"!=\": ";
			cin >> value;
			value != list;
			break;
		case 8:
			system("cls");
			cout << "������� �����, � ������� ������ �������� ��������� ������� �������� ������, ����� ���������� ��������� \"<=\": ";
			cin >> value;
			value <= list;
			break;
		case 9:
			system("cls");
			cout << "������� �����, � ������� ������ �������� ��������� ������� �������� ������, ����� ���������� ��������� \">=\": ";
			cin >> value;
			value >= list;
			break;
		case 10:
			system("cls");
			cout << "������� �������(�������) ���������: ";
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
