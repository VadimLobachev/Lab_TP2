#include "unit.h"
#include <iostream>
using namespace std;
unit::unit()
{
	Data = new int;
	*Data = 0;
}
unit::unit(int Value)
{
	Data = new int;
	*Data = Value;
}
unit::unit(const unit& init)
{
	Data = new int;
	*Data = *(init.Data);
}
unit::~unit()
{
	delete Data;
	Data = nullptr;
}
unit& unit::operator++()
{
	*(this->Data) += 1;
	return *this;
}
unit& unit::operator--()
{
	int value;
	cout << "Введите число, на которое вы хотите уменьшить целое число: ";
	cin >> value;
	*(this->Data) -= value;
	return *this;
}
unit& operator++(unit& obj, int)
{
	static unit tmp(obj);
	tmp.setData(obj.getData() + 2);
	obj.setData(tmp.getData());
	return tmp;
}
unit& operator--(unit& obj, int)
{
	static unit tmp(obj);
	tmp.setData(obj.getData() - 2);
	obj.setData(tmp.getData());
	return tmp;
}
void unit::print()
{
	std::cout << *Data << std::endl;
}
