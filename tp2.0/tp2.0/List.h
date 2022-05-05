#pragma once
typedef struct Element
{
	int data;
	Element* next;
	Element* prev;
} Element;
class List
{
private:
	Element* right = nullptr; //указатель на конечный элемент списка - инициализированный элемент
	Element* left = nullptr; //указатель на начальный элемент списка - инициализированный элемент
		int size = 0; //размер списка
public:
	//конструкторы
	List(); //конструктор без параметров
	explicit List(int size_st); //явный конструктор с параметрами (задаем размер списка)
	~List(); //деструктор
	List(const List& List_copy); //конструктор копирования
	//функции списка
	void push(int value); //добавление элемента в список
	void del(int num); //удаление элемента из списка
	void print(); //вывод списка на экран
	//геттеры и сеттеры
	Element* get_right();
	Element* get_left();
	void set_size(int& value); //поместить значение в список
	int get_size() const; //взять размер списка
	//перегруженные операторы
	friend void operator< (int value, const List& list);
	friend void operator> (int value, const List& list);
	friend void operator== (int value, const List& list);
	friend void operator!= (int value, const List& list);
	friend void operator<= (int value, const List& list);
	friend void operator>= (int value, const List& list);
	List* operator () (int l, int r);
};


