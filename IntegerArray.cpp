/* классы:
	1. ћассив элементов int
	2. exception bad_length
	3. exception bad_range
*/

#include "IntegerArray.h"

/* конструкторы */
IntegerArray::IntegerArray():_array_lenght(0), _my_array(nullptr), _f_index(0){}

IntegerArray::IntegerArray(size_t len) : _f_index(0), _array_lenght(len)
{
	if (_array_lenght >= (1 << 10)) { throw bad_length(_array_lenght); }
	this->_my_array = new int[_array_lenght] {};
}

IntegerArray::IntegerArray(int* arr, size_t len) : _f_index(0), _array_lenght(len)
{
	if (_array_lenght >= (1 << 10)) { throw bad_length(_array_lenght); }
	this->_my_array = arr;
}

/* деструктор */
IntegerArray::~IntegerArray()
{
	delete[] this->_my_array;
}

/* методы */
size_t IntegerArray::getSize()
{
	return _array_lenght;
}

void IntegerArray::resizeArray(size_t newlen)
{
	if (newlen >= (1 << 10)) { throw bad_length(newlen); }
	_array_lenght = newlen;
	int* newarr = new int[newlen] {};
	delete[] _my_array;
	_my_array = newarr;
}

void IntegerArray::setElement(int element, size_t index)
{
	if (index >= _array_lenght) { throw bad_range(index); }
	this->_my_array[index] = element;
}

int IntegerArray::getElement(size_t index) const
{
	if (index >= _array_lenght) { throw bad_range(index); }
	return _my_array[index];
}

void IntegerArray::insertElement(int element, size_t index)
{
	if (index > _array_lenght) { throw bad_range(index); }
	++_array_lenght;
	int* tmp = new int[_array_lenght] {};
	size_t j = 0;
	for (size_t i = 0; i < _array_lenght; ++i) {
		if (i == index) { 
			tmp[i] = element; 
			++j;
		}
		tmp[j] = this->_my_array[i];
		++j;
	}
	delete[] this->_my_array;
	this->_my_array = tmp;
}

size_t IntegerArray::findFirst(int el)
{
	size_t i = 0;
	do {
		if(this->_my_array[i] == el){
			_f_index = i;
			return i;
		}
		++i;
	} while (i < this->_array_lenght);
	return -1;
}

size_t IntegerArray::findNext(int el)
{
	size_t i = _f_index + 1;
	if (i == _array_lenght) { return -1; }
	do {
		if (this->_my_array[i] == el) {
			_f_index = i;
			return i;
		}
		++i;
	} while (i < this->_array_lenght);
	return -1;

}

size_t IntegerArray::countElements(int el)
{
	size_t counter = 0;
	for (size_t i = 0; i < _array_lenght; ++i) {
		if (_my_array[i] == el) { ++counter; }
	}
	return counter;
}

void IntegerArray::deleteElement(size_t index)
{
	if (index >= _array_lenght) { throw bad_range(index); }
	int* tmp = new int[_array_lenght-1] {};
	size_t j = 0;
	for (size_t i = 0; i < _array_lenght; ++i) {
		if (i == index) {
			++i;
		}
		tmp[j] = this->_my_array[i];
		++j;
	}
	delete[] this->_my_array;
	this->_my_array = tmp;
	--_array_lenght;
}

void IntegerArray::erase()
{
	delete[] this->_my_array;
	this->_array_lenght = 0;
	this->_my_array = nullptr;
}

IntegerArray& IntegerArray::operator=(const IntegerArray& arr)
{
	if (&arr == this) { return *this; }
	this->resizeArray(arr._array_lenght);
	for (size_t i = 0; i < _array_lenght; ++i) {
		this->_my_array[i] = arr._my_array[i];
	}
	return *this;
}

int& IntegerArray::operator[](size_t index)
{
	if (index >= _array_lenght) { throw bad_range(index); }
	return _my_array[index];
}

/* класс bad_length */
bad_length::bad_length(int r) : _length(r) { cout << "bad_length constructed\n"; }
bad_length::~bad_length() { cout << "\nbad_length destructed\n"; }
const char* bad_length::what() const { return "Bad_length exception. Length = "; }
int bad_length::getData() { return _length; }

/* класс bad_range */
bad_range::bad_range(int r) : _range(r) { cout << "bad_range constructed\n"; }
bad_range::~bad_range() { cout << "\nbad_range destructed\n"; }
const char* bad_range::what() const { return "Bad_range exception. Index = "; }
int bad_range::getData() { return _range; }