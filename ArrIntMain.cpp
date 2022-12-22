
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
		ia2 = new IntegerArray(-1);
	}
	catch (bad_length& e) {
		cout << "catch construct error\n" << e.what() << e.getData();
		ia2 = new IntegerArray();
	}

	try {
		cout << "\ntry resize";
		cout << "\nРазмер массива до: " << ia2->getSize() << endl;
		ia2->resizeArray(2000000);
	}
	catch (bad_length& e) {
		cout << "\ncatch resize error bad_length\n" << e.what() << e.getData();
		ia2->resizeArray(3);
	}
	cout << "Размер массива после: " << ia2->getSize() << endl;

	try {
		cout << "\ntry set element\n";
		ia2->setElement(5, 7);
	}
	catch (bad_range& e) {
		cout << "\ncatch set element error\n" << e.what() << e.getData();
		ia2->setElement(5, 2);
	}
	cout << "Элемент массива: " << ia2->getElement(2) << endl;

	*ia1 = *ia2;
	cout << "\nia1 = " << ia1 << "\tia2 = " << ia2 << endl;	// адреса объектов

	try {
		cout << "\ntry get element\n";
		cout << "Элемент массива: " << ia1->getElement(4) << endl;
	}
	catch (bad_range& e) {
		cout << "\ncatch get element error\n" << e.what() << e.getData();
		cout << "\nЭлемент массива: " << ia1->getElement(2) << endl;
	}

	try {
		cout << "\ntry [] element\n";
		(*ia1)[-7] = 11;
	}
	catch (bad_range& e) {
		cout << "\ncatch [] element error\n" << e.what() << e.getData();
		(*ia1)[0] = 11;
	}

	try {
		cout << "\n\ntry insert element\n";
		ia1->insertElement(999, 88);
	}
	catch (bad_range& e) {
		cout << "\ncatch insert element error\n" << e.what() << e.getData();
		ia1->insertElement(999, 1);
	}

	for (size_t i = 0; i < ia1->getSize(); ++i) { cout << (*ia1)[i] << " ";	}

	try {
		cout << "\n\ntry delete element\n";
		ia1->deleteElement(8);
	}
	catch (bad_range& e) {
		cout << "\ncatch delete element error\n" << e.what() << e.getData();
		ia1->deleteElement(1);
	}

	for (size_t i = 0; i < ia1->getSize(); ++i) { cout << (*ia1)[i] << " ";	}

	int* arr1 = new int[14]{ 1,4,2,5,3,6,1,4,2,5,3,6,2,4 };
	try {
		cout << "\n\ntry construct\n";
		ia3 = new IntegerArray(arr1, 14);
	}
	catch (bad_length& e) {
		cout << "\ncatch try construct error\n" << e.what() << e.getData();
		ia3 = new IntegerArray(arr1, 14);
	}
	for (size_t i = 0; i < ia3->getSize(); ++i) { cout << (*ia3)[i] << " ";	}

	cout << "\n\nКоличество цифр \"5\": " << ia3->countElements(5) << endl;
	cout << "Индексы в массиве цифры \"4\": " << endl;
	cout << "first el = " << ia3->findFirst(4);
	cout << "\nnext el = " << ia3->findNext(4);
	cout << "\nnext el = " << ia3->findNext(4);
	cout << "\nnext el = " << ia3->findNext(4);

	// вставка в начало
	ia3->insertElement(39,0);
	cout << "\n\nвставка в начало\n";
	for (size_t i = 0; i < ia3->getSize(); ++i) { cout << (*ia3)[i] << " "; }
	cout << "\ninserted at beginntng\n\n";

	// вставка в конец
	ia3->insertElement(59, ia3->getSize());
	cout << "\nвставка в конец\n";
	for (size_t i = 0; i < ia3->getSize(); ++i) { cout << (*ia3)[i] << " "; }
	cout << "\ninserted at end\n\n";

	ia3->deleteElement(0);
	ia3->deleteElement(ia3->getSize() - 1);
	for (size_t i = 0; i < ia3->getSize(); ++i) { cout << (*ia3)[i] << " "; }
	cout << "\ndeleted\n";

	delete ia1;
	delete ia2;
	delete ia3;
	cout << "\nEND PROGRAM\n";
	return 0;
}