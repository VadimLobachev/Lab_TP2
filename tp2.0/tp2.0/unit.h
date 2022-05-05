#pragma once
class unit
{
	int* Data; //Целочисленное значение
public:
	unit(); //Конструктор по умолчанию
	unit(int Value); //Конструктор с параметром
	explicit unit(const unit& init); //Конструктор копирования
	~unit(); //Деструктор
	int getData() { return *Data; } //Метод получения значения
	void setData(int Value = 0) { *Data = Value; } //Метод установки значения
	friend unit& operator++(unit& obj, int); //Постфиксная форма, дружественная функция, увеличивает на 2
	friend unit & operator--(unit & obj, int); //Постфиксная форма, дружественная функция, уменьшает на 2
	unit & operator++();//Префиксная форма, увеличивает на 1
	unit& operator--();//Префиксная форма, уменьшает на 1
	operator int() { return *Data; }
	void print();//Вывод на экран
};

