/* ������:
	1. ������ ��������� int
	2. exception bad_length
	3. exception bad_range
*/

#pragma once
#include<iostream>
#include<exception>

using namespace std;

class bad_length : public exception {
	size_t _length;
public:
	bad_length(size_t r);
	~bad_length();
	const char* what() const override;
	size_t getData();
};

class bad_range : public exception {
	size_t _range;
public:
	bad_range(size_t r);
	~bad_range();
	const char* what() const override;
	size_t getData();
};


class IntegerArray
{
	size_t _array_lenght;
	int* _my_array;
	size_t _f_index;		// ������ ���������� ��������

public:
	IntegerArray();
	IntegerArray(size_t len);
	IntegerArray(int* arr, size_t len);
	~IntegerArray();

	size_t getSize();								// ������� ������ �������
	void resizeArray(size_t newlen);				// �������� ������ �������
	void setElement(int element, size_t index);		// �������� ������� �������
	int getElement(size_t index) const;				// ������� �������� �������� �������
	void insertElement(int element, size_t index);	// �������� ������� � ������
	size_t findFirst(int el);			// ������� ������ ������� ���������� ��������
	size_t findNext(int el);			// ������� ������ ���������� ���������� ��������
	size_t countElements(int el);		// ������� ���������� �������� ���������
	void deleteElement(size_t index);	// �������� �������� �������
	void erase();						// �������� �������
	IntegerArray& operator=(const IntegerArray& arr);
	int& operator[](size_t index);
};