#include "List.h"
#include <iostream>
#include <locale>

using namespace std;
/* ������������ */
List::List() : right(0), left(0), size(0) {} //����������� ��� ���������� 
List::List(int size_st) : right(0), left(0)//����������� � ����������, ������ ������ � �������������� �������
{
	this->size = size_st; //���������� ������� ������������� ������
}
List::~List()
{
	if ((right == 0) || (size == 0))
	{
		delete right; //������� �������
		size = 0; //������ �������
	}
	else
	{
		while (right->next != 0) //���� �� ������ �� �������� ���������
		{
			Element* temp = right; //��������� ���������� �����, ����������� �� �������� �������
				right = temp->next; //������ ������� ��������� �� ��������� �� ��� �������,� ��������� - ��������
				delete temp; 
		}
		delete right; //������� �������
		size = 0; //������ �������
	}
}
List::List(const List& List_copy) : size(List_copy.size)
{
	int* buff = new int[List_copy.size]; //������ �������� ������, � ������� ����� ������� ���� ����� ������ ������
		Element* el_List = List_copy.right; //����� ����������-������� �������� ������
	for (int i = 0; i <= List_copy.size - 1; i++)
	{ //���� ������� �� ������ �� ����� ������
		buff[i] = el_List->data; //������� � ������ �������� �� ������
		el_List = el_List->next; //������ ��������� �� ��������� ������� ������
	}
	for (int i = 0; i < List_copy.size; i++)
		this->push(buff[i]); //������ � ����� ������ �������� �� �������
	delete[] buff; //������� �����
}
/* ������ ������ ������ */
void List::push(int value)
{
	Element* new_Element = new Element; //��������� ������ ��� ����� ������� ���������
		new_Element->next = NULL; //���������, ��� ���������� �� ���������� ������ �����
		new_Element->data = value; //���������� �������� � ���������
	if (left != NULL) //���� ������ �� ����
	{
		new_Element->prev = right; //��������� ����� �� ���������� ������� � �����.����
			right->next = new_Element; //��������� ����� ���������� �� ������� ��������
			right = new_Element; //������ ����� ������
	}
	else //���� ������ ������
	{
		new_Element->prev = NULL; //���������� ������� ��������� � �������
			right = left = new_Element; //������=�����=��� �������, ��� ������ ��������
	}
	size++;
}
void List::del(int num)
{
	setlocale(LC_ALL, "Rus");
	if (size == 0)
	{
		cout << "������ ����, ������� ������." << endl;
	}
	else {
		Element* temp = left; //��������� ����������-�������
		int deldata = 0; //����� ��� ��������� �������
		system("cls");
		for (int i = 0; i < num; i++)
		{
			temp = temp->next;
		}
		// ������� �� ��������, 
		// ������� ������������ ����������
		Element* prevTemp = temp->prev;
		// ������� �� ��������, ������� ������� �� ���������
		Element* nextTemp = temp->next;
		// ���� ������� �� ������
		if (prevTemp != nullptr)
			prevTemp->next = nextTemp;
		// ���� ������� �� �����
		if (nextTemp != nullptr)
			nextTemp->prev = prevTemp;
		if (num == 0)
			left = nextTemp;
		if (num == size - 1)
			right = prevTemp;
		// �������� ��������
		delete temp;
		size--;
	}
}
void List::print()
{
	if (size == 0)
	{
		cout << "������ ����, �������� ������." << endl;
	}
	else
	{
		Element* temp = left; //��������� ��������� �� ����� ���������� ��������
			//������� ������ � ������ //�������� ��������� �� ����� ������� ��������
			while (temp != nullptr) //���� �� �������� ������ ��������
			{
				if (temp->next == nullptr)
					cout << temp->data; //������� ������ ��������� �������� �� �����
				else
					cout << temp->data << " <--> ";
				temp = temp->next; //����� ������ �� ����� ���������� ��������
			}
		cout << "\n";
	}
}
Element* List::get_right()
{
	return right;
}
Element* List::get_left()
{
	return left;
}
int List::get_size() const
{
	return size;
}
void List::set_size(int& value)
{
	size = value;
}
void operator < (int value, const List& list)
{
	Element* left = list.left;
	while (left->next != nullptr)
	{
		if (left->data < value)
			cout << left->data << " < " << value << " - true" << endl;
		else
			cout << left->data << " < " << value << " - false" << endl;
		left = left->next;
		
	}
}
void operator > (int value, const List& list)
{
	Element* left = list.left;
	while (left->next != nullptr)
	{
		if (left->data > value)
			cout << left->data << " > " << value << " - true" << endl;
		else
			cout << left->data << " > " << value << " - false" << endl;
		left = left->next;
	}
}
void operator == (int value, const List& list)
{
	Element* left = list.left;
	while (left->next != nullptr)
	{
		if (left->data == value)
			cout << left->data << " = " << value << " - true" << endl;
		else
			cout << left->data << " = " << value << " - false" << endl;
		left = left->next;
	}
}
void operator != (int value, const List& list)
{
	Element* left = list.left;
	while (left->next != nullptr)
	{
		if (left->data != value)
			cout << left->data << " != " << value << " - true" << endl;
		else
			cout << left->data << " != " << value << " - false" << endl;
		left = left->next;
	}
}
void operator <= (int value, const List& list)
{
	Element* left = list.left;
	while (left->next != nullptr)
	{
		if (left->data <= value)
			cout << left->data << " <= " << value << " - true" << endl;
		else
			cout << left->data << " <= " << value << " - false" << endl;
		left = left->next;
	}
}
void operator >= (int value, const List& list)
{
	Element* left = list.left;
	while (left->next != nullptr)
	{
		if (left->data <= value)
			cout << left->data << " >= " << value << " - false" << endl;
		else
			cout << left->data << " >= " << value << " - true" << endl;
		
			left = left->next;
	}
}
List* List::operator() (int l, int r)
{
	List* temp = new List;
	Element* tmp = left;
	int* arr = new int[r - l];
	for (int i = 0; i < l; ++i)
	{
		tmp = tmp->next;
	}
	for (int i = l; i <= r; ++i)
	{
		arr[i - l] = tmp->data;
		tmp = tmp->next;
		temp->push(arr[i - l]);
	}
	return temp;
}
