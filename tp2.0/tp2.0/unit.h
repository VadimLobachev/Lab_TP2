#pragma once
class unit
{
	int* Data; //������������� ��������
public:
	unit(); //����������� �� ���������
	unit(int Value); //����������� � ����������
	explicit unit(const unit& init); //����������� �����������
	~unit(); //����������
	int getData() { return *Data; } //����� ��������� ��������
	void setData(int Value = 0) { *Data = Value; } //����� ��������� ��������
	friend unit& operator++(unit& obj, int); //����������� �����, ������������� �������, ����������� �� 2
	friend unit & operator--(unit & obj, int); //����������� �����, ������������� �������, ��������� �� 2
	unit & operator++();//���������� �����, ����������� �� 1
	unit& operator--();//���������� �����, ��������� �� 1
	operator int() { return *Data; }
	void print();//����� �� �����
};

