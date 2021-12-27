#include <iostream>
#include "QueueBase.h"
#include "Queue1.h"
#include "Queue2.h"

using namespace std;

template<typename T>
void MyFuncWithPointer(QueueBase<T>* s)
{
	cout << s->Peek() << endl;
}

template<typename T>
void MyFuncWithReference(QueueBase<T>& s)
{
	cout << s.Peek() << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	Queue1<int> q1;
	q1.Push(2);
	q1.Push(6);
	q1.Push(8);
	q1.Push(1);
	q1.Push(4);

	cout << q1;

	cout << "Первый элемент : " << q1.Peek() << "; число элементов в очереди : " << q1.GetSize() << endl << endl;

	Queue2<int> q2;
	q2.Push(2);
	q2.Push(6);
	q2.Push(8);
	q2.Push(1);
	q2.Push(4);

	cout << q2;

	cout << "Первый элемент : " << q2.Peek() << "; число элементов в очереди : " << q2.GetSize() << endl << endl;

	cout << "Вызов функции с аргументом указателя" << endl;
	cout << "Элемент из первой очереди" << endl;
	MyFuncWithPointer(&q1);
	cout << "Элемент из второй очереди" << endl;
	MyFuncWithPointer(&q2);
	cout << "Вызов функции с аргументом ссылки" << endl;
	cout << "Элемент из первой очереди" << endl;
	MyFuncWithReference(q1);
	cout << "Элемент из второй очереди" << endl;
	MyFuncWithReference(q2);



	return 0;
}

