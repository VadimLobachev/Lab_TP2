#include "List.h"
#include <iostream>
#include <locale>

using namespace std;
/* КОНСТРУКТОРЫ */
List::List() : right(0), left(0), size(0) {} //конструктор без параметров 
List::List(int size_st) : right(0), left(0)//конструктор с параметром, задает размер и инициализирует элемент
{
	this->size = size_st; //вызванному объекту устанавливаем размер
}
List::~List()
{
	if ((right == 0) || (size == 0))
	{
		delete right; //удаляем вершину
		size = 0; //размер нулевой
	}
	else
	{
		while (right->next != 0) //пока не дойдем до нулевого указателя
		{
			Element* temp = right; //временная переменная юнита, присваиваем ей значение вершины
				right = temp->next; //теперь вершина указывает на следующий за ней элемент,а временную - удаляеям
				delete temp; 
		}
		delete right; //удаляем вершину
		size = 0; //размер нулевой
	}
}
List::List(const List& List_copy) : size(List_copy.size)
{
	int* buff = new int[List_copy.size]; //вводим буферный массив, в котором будем хранить наши числа нового списка
		Element* el_List = List_copy.right; //новая переменная-вершина будущего списка
	for (int i = 0; i <= List_copy.size - 1; i++)
	{ //пока счетчик не дойдет до конца списка
		buff[i] = el_List->data; //заносим в массив значения из списка
		el_List = el_List->next; //ставим указатель на следующий элемент списка
	}
	for (int i = 0; i < List_copy.size; i++)
		this->push(buff[i]); //вносим в новый список значения из массива
	delete[] buff; //удаляем буфер
}
/* МЕТОДЫ КЛАССА СПИСОК */
void List::push(int value)
{
	Element* new_Element = new Element; //Выделение памяти под новый элемент структуры
		new_Element->next = NULL; //Указываем, что изначально по следующему адресу пусто
		new_Element->data = value; //Записываем значение в структуру
	if (left != NULL) //Если список не пуст
	{
		new_Element->prev = right; //Указываем адрес на предыдущий элемент в соотв.поле
			right->next = new_Element; //Указываем адрес следующего за хвостом элемента
			right = new_Element; //Меняем адрес хвоста
	}
	else //Если список пустой
	{
		new_Element->prev = NULL; //Предыдущий элемент указывает в пустоту
			right = left = new_Element; //Голова=Хвост=тот элемент, что сейчас добавили
	}
	size++;
}
void List::del(int num)
{
	setlocale(LC_ALL, "Rus");
	if (size == 0)
	{
		cout << "список пуст, удалять нечего." << endl;
	}
	else {
		Element* temp = left; //временная переменная-вершина
		int deldata = 0; //место под удаленный элемент
		system("cls");
		for (int i = 0; i < num; i++)
		{
			temp = temp->next;
		}
		// Доходим до элемента, 
		// который предшествует удаляемому
		Element* prevTemp = temp->prev;
		// Доходим до элемента, который следует за удаляемым
		Element* nextTemp = temp->next;
		// Если удаляем не голову
		if (prevTemp != nullptr)
			prevTemp->next = nextTemp;
		// Если удаляем не хвост
		if (nextTemp != nullptr)
			nextTemp->prev = prevTemp;
		if (num == 0)
			left = nextTemp;
		if (num == size - 1)
			right = prevTemp;
		// Удаление элемента
		delete temp;
		size--;
	}
}
void List::print()
{
	if (size == 0)
	{
		cout << "список пуст, выводить нечего." << endl;
	}
	else
	{
		Element* temp = left; //Временный указатель на адрес последнего элемента
			//ВЫВОДИМ СПИСОК С НАЧАЛА //Временно указываем на адрес первого элемента
			while (temp != nullptr) //Пока не встретим пустое значение
			{
				if (temp->next == nullptr)
					cout << temp->data; //Выводим каждое считанное значение на экран
				else
					cout << temp->data << " <--> ";
				temp = temp->next; //Смена адреса на адрес следующего элемента
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
