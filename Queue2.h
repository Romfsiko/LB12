#pragma once

#include "QueueBase.h"
#include "List2.h"

template<typename T>
class Queue2 : public QueueBase<T>
{
private:

	List2<T> list2;

public:

	Queue2();

	Queue2(const Queue2& other);

	Queue2(Queue2&& other);

	~Queue2() override;

	int GetSize() const override;

	void Push(const T& element) override;

	T Pop() override;

	T Peek() const override;

	Queue2& operator=(const Queue2& other);
	Queue2& operator=(Queue2&& other);

	template<typename T>
	friend std::ostream& operator<< (std::ostream& os, const Queue2<T>& obj);
};

template<typename T>
Queue2<T>::Queue2() { }

template<typename T>
Queue2<T>::Queue2(const Queue2& other)
{
	list2 = other.list2;
}

template<typename T>
Queue2<T>::Queue2(Queue2&& other)
{
	list2 = std::move(other.list2);
}

template<typename T>
Queue2<T>::~Queue2() {}

template<typename T>
int Queue2<T>::GetSize() const
{
	return list2.getsize();
}

template<typename T>
void Queue2<T>::Push(const T& element)
{
	list2.push_back(element);
}

template<typename T>
T Queue2<T>::Pop()
{
	return list2.pop_front();
}

template<typename T>
T Queue2<T>::Peek() const
{
	return list2.sel_el(0);
}

template<typename T>
Queue2<T>& Queue2<T>::operator=(const Queue2<T>& other)
{
	if (this == &other)
	{
		return *this;
	}

	list2->clear();

	list2 = other.list2;
}

template<typename T>
Queue2<T>& Queue2<T>::operator=(Queue2<T>&& other)
{
	if (this == &other)
	{
		return *this;
	}

	list2->clear();

	list2 = std::move(other.list2);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Queue2<T>& obj)
{
	for (size_t i = 0; i < obj.list2.getsize(); i++)
	{
		os << obj.list2.sel_el(i) << " ";
	}

	os << std::endl;

	return os;
}
