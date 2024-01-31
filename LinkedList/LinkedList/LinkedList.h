#pragma once
#include <iostream>
#include "Iterator.h"
template<typename AnyType>
class LinkedList
{
public:

	LinkedList();
	LinkedList(const LinkedList<AnyType>& other);
	~LinkedList();

	void initialize();
	void destroy();

	Iterator<AnyType> begin() const;
	Iterator<AnyType> end()  const;

	AnyType first() const;
	AnyType last() const;

	bool contains(const AnyType object) const;
	bool isEmpty() const;
	void print() const;

	void pushFront(const AnyType& value);
	void PushBack(const AnyType& value);

	AnyType PopFront();
	AnyType PopBack();

	bool insert(const AnyType& value, int index);
	bool remove(const AnyType& value);

	const void print();
	void initialize();
	const bool isEmpty();
	bool getData(Iterator<AnyType>& iter, int index);
	const bool getLength();
	
	void operator =(const LinkedList<AnyType>& otherLinkedList);

	void sort();





private:
	Node m_first;
	Node m_last;
	int m_nodeCount;







};

template<typename AnyType>
inline LinkedList<AnyType>::LinkedList(const LinkedList<AnyType>& other)
{
	*this = other;
}
