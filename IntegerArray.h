/* классы:
	1. IntegerArray
	2. bad_length
	3. bad_range
*/

#pragma once
#include<iostream>
#include<exception>

using namespace std;

class bad_length : public exception {
	int _length;
public:
	bad_length(int r);
	~bad_length();
	const char* what() const override;
	int getData();
};

class bad_range : public exception {
	int _range;
public:
	bad_range(int r);
	~bad_range();
	const char* what() const override;
	int getData();
};


class IntegerArray
{
	size_t _array_lenght;
	int* _my_array;
	size_t _f_index;		// индекс найденного элемента

public:
	IntegerArray();
	IntegerArray(size_t len);
	IntegerArray(int* arr, size_t len);
	~IntegerArray();

	size_t getSize();								// вернуть размер массива
	void resizeArray(size_t newlen);				// изменить размер массива
	void setElement(int element, size_t index);		// изменить элемент массива
	int getElement(size_t index) const;				// вернуть значение элемента массива
	void insertElement(int element, size_t index);	// вставить элемент в массив
	size_t findFirst(int el);			// вернуть индекс первого найденного элемента
	size_t findNext(int el);			// вернуть индекс следующего найденного элемента
	size_t countElements(int el);		// вернуть количество заданных элементов
	void deleteElement(size_t index);	// удаление элемента массива
	void erase();						// удаление массива
	IntegerArray& operator=(const IntegerArray& arr);	// копирование содержимого объекта
	int& operator[](size_t index);		// get, set по индексу
};