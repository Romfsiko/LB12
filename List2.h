#pragma once

#include <iostream>

template<typename T>
class List2 // ����� ����������� ����������� ������
{
private:

	class Node // ����� ���������
	{
	public:
		Node(T data = T(), Node* pNext = nullptr); // �����������

		Node* pNext; // ���������� ������
		T data; // ���������� ������
	};

	int size; // ���-�� ��
	Node* head; // ��������� �� ������ ������
	Node* tail; // ��������� �� ����� ������

public:

	List2();

	List2(const List2& other);

	List2(List2&& other);

	~List2();

	void push_front(const T& data); // ��������� ������� � ������

	void push_back(const T& data); //��������� ������� � �����

	T pop_front(); // ������� ����� ������ �������

	T removeAT(const int index); // ������� ������� � ����������� �����

	T pop_back(); // ������� ��������� �������

	void clear(); // ������� ��� ��������

	int getsize() const; // �������� ���-�� ��

	T& sel_el(const int index) const; // ���������� ������� �� �������

	List2& operator=(const List2& other);

	List2& operator=(List2&& other);

};

template<typename T>
List2<T>::Node::Node(T data, Node* pNext) : data(data), pNext(pNext) { }

template<typename T>
List2<T>::List2() : size(0), head(nullptr), tail(nullptr) { }

template<typename T>
List2<T>::List2(const List2& other) : size(0), head(nullptr), tail(nullptr)
{
	for (int i = 0; i < other.size; i++)
	{
		this->push_back(other.sel_el(i));
	}
}

template<typename T>
List2<T>::List2(List2&& other) : size(other.size), head(other.head), tail(other.tail)
{
	other.size = NULL;
	other.head = nullptr;
	other.tail = nullptr;
}

template<typename T>
List2<T>::~List2()
{
	clear();
}

template<typename T>
void List2<T>::push_front(const T& data)
{
	if (head == nullptr) // ���� ��� ��� �� ������ ���������
	{
		head = tail = new Node(data);

		head->pNext = tail;
		tail->pNext = head;
	}
	else
	{
		head = new Node(data, head);
		tail->pNext = head;
	}
	size++;
}

template<typename T>
void List2<T>::push_back(const T& data)
{
	if (head == nullptr) // ���� ��� ��� �� ������ ���������
	{
		head = tail = new Node(data);

		head->pNext = tail;
		tail->pNext = head;
	}
	else
	{
		Node* current = this->tail;
		current->pNext = new Node(data, head);
		tail = current->pNext;
	}
	size++;
}

template<typename T>
T List2<T>::pop_front()
{
	Node* temp = head;

	T data = temp->data;

	if (size > 1)
	{
		head = head->pNext;
		tail->pNext = head;
	}
	else
		tail = head = nullptr;

	delete temp;
	size--;

	return data;

}

template<typename T>
T List2<T>::removeAT(const int index)
{
	if (index > this->size - 1) // ���� ��������� ������ ��������� ��� ������ ������
	{
		std::cout << "��������� ������ ��������� ��� ������!" << std::endl;
		return T();
	}
	else if (index == 0) // ���� ������ 0, �� ���������� ��� ������� �������
	{
		return pop_front();
	}
	else
	{
		Node* previous = this->head;  // �������� ��� ��������� ��������� � ������ ���� ���������� (this ���������)

		for (int i = 0; i < index - 1; i++) //���� ���������, ������� ����� �� ���� ���������, ������� �� ����� �������
		{
			previous = previous->pNext;

		}
		Node* toDelete = previous->pNext; // ������ ��������� �� ���������, ������� �� ����� �������
		T data = toDelete->data;
		previous->pNext = toDelete->pNext; // �� ����� ���������, ������� ����� ������� ������ ��������� ��������
		delete toDelete; // ������� ���������, �� ������� �������
		size--;
		return data;
	}
}

template<typename T>
T List2<T>::pop_back()
{
	return removeAT(size - 1);
}

template<typename T>
void List2<T>::clear()
{
	if (this != nullptr)
	{
		while (size) // ���� �� ����� 0
		{
			pop_front();
		}
	}

}

template<typename T>
int List2<T>::getsize() const
{
	return size;
}

template<typename T>
T& List2<T>::sel_el(const int index) const
{

	if (index > this->size - 1) // ���� ��������� ������ ��������� ��� ������ ������
	{
		std::cout << "��������� ������ ��������� ��� ������ ������! ��������� ���������� ���������!" << std::endl;
		abort();
	}

	if (index == 0)
		return head->data;
	else if (index == this->size - 1)
		return tail->data;
	else
	{
		Node* current = head;

		for (int i = 0; i < index; i++)
		{
			current = current->pNext;
		}

		return current->data;
	}

}

template<typename T>
List2<T>& List2<T>::operator=(const List2& other)
{
	size = 0;
	head = nullptr;
	tail = nullptr;

	if (this == &other)
	{
		return *this;
	}

	clear();

	for (int i = 0; i < other.size; i++)
	{
		this->push_back(other.sel_el(i));
	}
}

template<typename T>
List2<T>& List2<T>::operator=(List2&& other)
{
	if (this == &other)
	{
		return *this;
	}

	clear();

	size = other.size;
	this->head = other.head;
	this->tail = other.tail;

	other.size = NULL;
	other.head = nullptr;
	other.tail = nullptr;
}
