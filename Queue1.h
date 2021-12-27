#pragma once

#include "QueueBase.h"
#include "List.h"

template <typename T>
class Queue1 : public QueueBase<T>
{
private:

	List<T> list;

public:

	Queue1();

	Queue1(const Queue1& other);

	Queue1(Queue1&& other);

	~Queue1();

	int GetSize() const;

	void Push(const T& element);

	T Pop();

	T Peek() const;

	Queue1& operator=(const Queue1& other);
	Queue1& operator=(Queue1&& other);

	template<typename T>
	friend std::ostream& operator<< (std::ostream& os, const Queue1<T>& obj);
};

template<typename T>
Queue1<T>::Queue1() { }

template<typename T>
Queue1<T>::Queue1(const Queue1& other)
{
	list = other.list;
}

template<typename T>
Queue1<T>::Queue1(Queue1&& other)
{
	list = std::move(other.list);
}

template<typename T>
Queue1<T>::~Queue1() {}

template<typename T>
int Queue1<T>::GetSize() const
{
	return list.getsize();
}

template<typename T>
void Queue1<T>::Push(const T& element)
{
	list.push_back(element);
}

template<typename T>
T Queue1<T>::Pop()
{
	return list.pop_front();
}

template<typename T>
T Queue1<T>::Peek() const
{
	return list.sel_el(0);
}

template<typename T>
Queue1<T>& Queue1<T>::operator=(const Queue1<T>& other)
{
	if (this == &other)
	{
		return *this;
	}

	list.clear();

	list = other.list;
}

template<typename T>
Queue1<T>& Queue1<T>::operator=(Queue1<T>&& other)
{
	if (this == &other)
	{
		return *this;
	}

	list.clear();

	list = std::move(other.list);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Queue1<T>& obj)
{
	for (size_t i = 0; i < obj.list.getsize(); i++)
	{
		os << obj.list.sel_el(i) << " ";
	}

	os << std::endl;

	return os;
}
