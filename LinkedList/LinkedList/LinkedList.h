#pragma once
#include <iostream>
#include "Iterator.h"
template<typename AnyType>
class LinkedList
{

public:

	LinkedList<AnyType>();
	/// <summary>
	/// 
	/// </summary>
	/// <param name="other"></param>
	LinkedList<AnyType>(const LinkedList<AnyType>& other);

	//deconsrtuctor
	~LinkedList();

	/// <summary>
	/// 
	/// </summary>
	void initialize();

	/// <summary>
	/// 
	/// </summary>
	void destroy();

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	Iterator<AnyType> begin() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	Iterator<AnyType> end()  const;

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	AnyType first() const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	AnyType last() const;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="object"></param>
	/// <returns></returns>
	bool contains(const AnyType object) const;
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	bool isEmpty() const;
	
	/// <summary>
	/// 
	/// </summary>
	void print() const;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="value"></param>
	void pushFront(const AnyType& value);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="value"></param>
	void PushBack(const AnyType& value);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	AnyType PopFront();
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	AnyType PopBack();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="value"></param>
	/// <param name="index"></param>
	/// <returns></returns>
	bool insert(const AnyType& value, int index);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="value"></param>
	/// <returns></returns>
	bool remove(const AnyType& value);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	const void print();
	
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="iter"></param>
	/// <param name="index"></param>
	/// <returns></returns>
	bool getData(Iterator<AnyType>& iter, int index);
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	const bool getLength();
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="otherLinkedList"></param>
	void operator =(const LinkedList<AnyType>& otherLinkedList);

	/// <summary>
	/// 
	/// </summary>
	void sort();

	private:

		/// <summary>
		/// 
		/// </summary>
		Node<AnyType>* m_first;

		/// <summary>
		/// 
		/// </summary>
		Node <AnyType>* m_last;

		/// <summary>
		/// 
		/// </summary>
		int m_nodeCount;











};

template<typename AnyType>
inline LinkedList<AnyType>::LinkedList()
{
	*this = 0;
}

template<typename AnyType>
inline LinkedList<AnyType>::LinkedList(const LinkedList<AnyType>& other)
{
	*this = other;
	
	m_first = other.m_first;
	m_last = other.m_last;

	for (Iterator<AnyType>)
}


template<typename AnyType>
inline void LinkedList<AnyType>::initialize()
{
	
}

template<typename AnyType>
inline void LinkedList<AnyType>::destroy()
{
}

template<typename AnyType>
inline Iterator<AnyType> LinkedList<AnyType>::begin() const
{
	return Iterator<AnyType>();
}

template<typename AnyType>
inline Iterator<AnyType> LinkedList<AnyType>::end() const
{

	if (!m_last)
		return Iterator<AnyType>(nullptr);

	return Iterator<AnyType>(m_last->next);
}

template<typename AnyType>
inline AnyType LinkedList<AnyType>::first() const
{
	return AnyType();
}

template<typename AnyType>
inline AnyType LinkedList<AnyType>::last() const
{
	return AnyType();
}

template<typename AnyType>
inline bool LinkedList<AnyType>::contains(const AnyType object) const
{
	return false;
}

template<typename AnyType>
inline bool LinkedList<AnyType>::isEmpty() const
{
	return false;
}

template<typename AnyType>
inline void LinkedList<AnyType>::print() const
{
}

template<typename AnyType>
inline void LinkedList<AnyType>::pushFront(const AnyType& value)
{
	//create a new node that contains the given value 
	Node<AnyType>* newNode = new Node<AnyType>(value);

	//set first's previous to be the new node
	m_first->previous = newNode;

	//set the new node's next to be first.
	newNode->next = m_first;

	//set first to be the new node
	m_first = newNode;

	//check if the only node is the new node we just made and if so make it the last as well as the first. This will also make both of new node's next and previous null pointer's
	if (m_nodeCount == 0)
		m_last = newNode;
	//increase the amount of nodes within the list being tracked
	m_nodeCount++;
}

template<typename AnyType>
inline void LinkedList<AnyType>::PushBack(const AnyType& value)
{
	//create a new node that contains the given value 
	Node<AnyType>* newNode = new Node<AnyType>(value);

	//set the last's next to be the new node
	m_last->next = newNode;

	//set new node's previous to be last
	newNode->previous = m_last;

	//set the last node to be the new node
	m_last = newNode;

	//check if the only node is the new node we just made and if so make it the first as well as the last. This will also make both of new node's next and previous null pointer's
	if (m_nodeCount == 0)
		m_first = newNode;

	//increase the amount of nodes within the list being tracked
	m_nodeCount++;
}

template<typename AnyType>
inline AnyType LinkedList<AnyType>::PopFront()
{
	//save data inside of first in local variable
	AnyType value = m_first->data;
	
	//make the next of first the new first
	m_first = m_first->next;

	//delete the old first aka new first's previous 
	delete m_first->previous;

	//make the new first's previous null pointer
	m_first->previous = nullptr;

	//reduce the nodecount by 1
	m_nodeCount--;

	//return the data that was in the previous first
	return value;
}

template<typename AnyType>
inline AnyType LinkedList<AnyType>::PopBack()
{
	//save data inside of first in local variable
	AnyType value = m_last->data;

	//make the previous of last the new last
	m_last = m_last->previous;

	//delete the old last aka new last's next
	delete m_last->next;

	//make the new last's next null pointer
	m_last->next = nullptr;
	
	//reduce the nodecount by 1
	m_nodeCount--;

	//return the data that was in the previous last
	return value;
}

template<typename AnyType>
inline bool LinkedList<AnyType>::insert(const AnyType& value, int index)
{
	return false;
}

template<typename AnyType>
inline bool LinkedList<AnyType>::remove(const AnyType& value)
{
	return false;
}

template<typename AnyType>
inline const void LinkedList<AnyType>::print()
{
	return void();
}

template<typename AnyType>
inline bool LinkedList<AnyType>::getData(Iterator<AnyType>& iter, int index)
{
	return false;
}

template<typename AnyType>
inline const bool LinkedList<AnyType>::getLength()
{
	return false;
}

template<typename AnyType>
inline void LinkedList<AnyType>::operator=(const LinkedList<AnyType>& otherLinkedList)
{
}

template<typename AnyType>
inline void LinkedList<AnyType>::sort()
{
}


