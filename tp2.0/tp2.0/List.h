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
	Element* right = nullptr; //��������� �� �������� ������� ������ - ������������������ �������
	Element* left = nullptr; //��������� �� ��������� ������� ������ - ������������������ �������
		int size = 0; //������ ������
public:
	//������������
	List(); //����������� ��� ����������
	explicit List(int size_st); //����� ����������� � ����������� (������ ������ ������)
	~List(); //����������
	List(const List& List_copy); //����������� �����������
	//������� ������
	void push(int value); //���������� �������� � ������
	void del(int num); //�������� �������� �� ������
	void print(); //����� ������ �� �����
	//������� � �������
	Element* get_right();
	Element* get_left();
	void set_size(int& value); //��������� �������� � ������
	int get_size() const; //����� ������ ������
	//������������� ���������
	friend void operator< (int value, const List& list);
	friend void operator> (int value, const List& list);
	friend void operator== (int value, const List& list);
	friend void operator!= (int value, const List& list);
	friend void operator<= (int value, const List& list);
	friend void operator>= (int value, const List& list);
	List* operator () (int l, int r);
};


