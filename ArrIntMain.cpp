
/*
	Основные конструкции C++.
	Модуль 7. Исключения. 
	7.7 Домашнее задание "Контейнер данных IntegerArray"
*/

#include <iostream>
#include <string>
#include <locale>
#include "IntegerArray.h"

int main() {
	setlocale(LC_ALL, "ru-RU");

	IntegerArray* ia1 = new IntegerArray();
	IntegerArray* ia2;
	IntegerArray* ia3;

	try {
		cout << "\ntry construct\n";
		ia2 = new IntegerArray(-5);
	}
	catch (bad_length& e) {
		cout << "\ncatch construct error\n" << e.what() << e.getData();
		ia2 = new IntegerArray();
	}

	for (size_t i = 0; i < ia2->getSize(); ++i) { cout << (*ia2)[i]; }

	try {
		cout << "\ntry resize";
		cout << "\nРазмер массива до: " << ia2->getSize() << endl;
		ia2->resizeArray(-90);
	}
	catch (bad_length& e) {
		cout << "\ncatch resize error bad_length\n" << e.what() << e.getData();
	}
	catch (bad_range& e) {
		cout << "\ncatch resize error bad_range\n" << e.what() << e.getData();
	}
	cout << "Размер массива после: " << ia2->getSize() << endl;

	try {
		cout << "\ntry set element";
		ia2->setElement(-5, 98);
	}
	catch (bad_range& e) {
		cout << "\ncatch set element error\n" << e.what() << e.getData();
		ia2->resizeArray(100);
		ia2->setElement(333, 98);
	}
	cout << "\nЭлемент массива2: " << ia2->getElement(98) << endl;

	*ia1 = *ia2;						// копирую содержимое объекта
	cout << "ia1 = " << ia1 << "\tia2 = " << ia2 << endl;	// адреса объектов

	try {
		cout << "\ntry get element\n";
		cout << "Элемент массива1: " << ia1->getElement(200) << endl;
	}
	catch (bad_range& e) {
		cout << "\ncatch get element error\n" << e.what() << e.getData();
		cout << "\nЭлемент массива1: " << ia1->getElement(98) << endl;
	}

	try {
		cout << "\ntry [] element\n";
		(*ia1)[2000] = 11;
	}
	catch (bad_range& e) {
		cout << "\ncatch [] element error\n" << e.what() << e.getData();
		(*ia1)[0] = 11;
	}

	(*ia2)[1] = 12;
	(*ia1)[2] = 13;
	cout << "\n";
	for (size_t i = 0; i < ia1->getSize(); ++i) { cout << (*ia1)[i]; }
	cout << "\n";
	for (size_t i = 0; i < ia2->getSize(); ++i) { cout << (*ia2)[i]; }

	cout << "\n\nОбъект на стеке\n\n";
	IntegerArray c = IntegerArray(20);
	IntegerArray b = IntegerArray(10);

	c[5] = 55;
	for (size_t i = 0; i < c.getSize(); ++i) { cout << c[i]; }
	cout << "\n";
	b[6] = 44;
	for (size_t i = 0; i < b.getSize(); ++i) { cout << b[i]; }

	cout << "\n\n";
	for (size_t i = 0; i < c.getSize(); ++i) { c[i] = i; }
	for (size_t i = 0; i < c.getSize(); ++i) { cout << c[i] << " "; }

	cout << "\n";
	for (size_t i = 0; i < b.getSize(); ++i) { b[i] = i + 10; }
	for (size_t i = 0; i < b.getSize(); ++i) { cout << b[i] << " "; }

	cout << "\n";
	b = c;
	cout << "\n&c = " << &c << "\t&b = " << &b << endl;
	for (size_t i = 0; i < c.getSize(); ++i) { cout << c[i] << " ";	}
	cout << "\n";
	for (size_t i = 0; i < b.getSize(); ++i) { cout << b[i] << " ";	}

	ia1->erase();
	cout << "\n\nia1.erase() " << ia1->getSize() << "\n";

	*ia1 = b;
	cout << "\n";
	for (size_t i = 0; i < ia1->getSize(); ++i) { cout << (*ia1)[i] << " "; }

	try {
		cout << "\n\ntry insert element\n";
		ia1->insertElement(999, 50);
	}
	catch (bad_range& e) {
		cout << "\ncatch insert element error\n" << e.what() << e.getData();
		ia1->insertElement(999, 1);
	}

	for (size_t i = 0; i < ia1->getSize(); ++i) { cout << (*ia1)[i] << " ";	}

	try {
		cout << "\n\ntry delete element\n";
		ia1->deleteElement(60);
	}
	catch (bad_range& e) {
		cout << "\ncatch delete element error\n" << e.what() << e.getData();
		ia1->deleteElement(1);
	}

	for (size_t i = 0; i < ia1->getSize(); ++i) { cout << (*ia1)[i] << " ";	}

	int* arr1 = new int[14]{ 1,4,2,5,3,6,1,4,2,5,3,6,2,4 };
	try {
		cout << "\n\ntry construct\n";
		ia3 = new IntegerArray(arr1, -9);
	}
	catch (bad_length& e) {
		cout << "\ncatch construct error\n" << e.what() << e.getData();
		ia3 = new IntegerArray(arr1, 14);
	}
	cout << "\nsize = " << ia3->getSize() << "\n";
	for (size_t i = 0; i < ia3->getSize(); ++i) { cout << (*ia3)[i] << " ";	}
	cout << "\nКоличество цифр \"2\": " << ia3->countElements(2) << endl;
	cout << "Количество цифр \"5\": " << ia3->countElements(5) << endl << endl;

	cout << "Индексы в массиве цифры \"4\": " << endl;
	cout << "first el = " << ia3->findFirst(4);
	cout << "\nnext el = " << ia3->findNext(4);
	cout << "\nnext el = " << ia3->findNext(4);
	cout << "\nnext el = " << ia3->findNext(4);

	cout << "\n\nfirst el = " << ia3->findFirst(4);
	cout << "\nnext el = " << ia3->findNext(4);
	cout << "\n\n";

	// вставка в начало
	ia3->insertElement(39, 0);
	for (size_t i = 0; i < ia3->getSize(); ++i) { cout << (*ia3)[i] << " "; }
	cout << "\ninserted at beginntng\n\n";

	// вставка в конец
	ia3->insertElement(59, ia3->getSize());
	for (size_t i = 0; i < ia3->getSize(); ++i) { cout << (*ia3)[i] << " "; }
	cout << "\ninserted at end\n\n";

	ia3->deleteElement(0);
	ia3->deleteElement(ia3->getSize() - 1);
	for (size_t i = 0; i < ia3->getSize(); ++i) { cout << (*ia3)[i] << " "; }
	cout << "\ndeleted\n";


	delete ia1;
	delete ia2;
	delete ia3;
	cout << "\n\nEND PROGRAM\n";
	return 0;
}
