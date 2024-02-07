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
	/// set the default values for the first node pointer, the last node pointer, and the node count
	/// </summary>
	void initialize();

	/// <summary>
	/// deletes all nodes in the LinkedList
	/// </summary>
	void destroy();

	/// <summary>
	/// returns an iterator pointing to the first node in the LinkedList
	/// </summary>
	/// <returns></returns>
	Iterator<AnyType> begin() const;
	
	/// <summary>
	/// returns the next item after the last node in the LinkedList
	/// </summary>
	/// <returns></returns>
	Iterator<AnyType> end()  const;

	/// <summary>
	/// returns the first value in the LinkedList
	/// </summary>
	/// <returns></returns>
	AnyType first() const;
	
	/// <summary>
	/// returns the last value in the LinkedList
	/// </summary>
	/// <returns></returns>
	AnyType last() const;

	/// <summary>
	/// checks to see if the given item is in the LinkedList
	/// </summary>
	/// <param name="object"></param>
	/// <returns></returns>
	bool contains(const AnyType object) const;
	
	/// <summary>
	/// returns whether or not the LinkedList has any nodes in it
	/// </summary>
	/// <returns></returns>
	bool isEmpty() const;
	
	/// <summary>
	/// prints the values for all the nodes
	/// </summary>
	void print() const;

	/// <summary>
	/// adds a new node to the beginning of the LinkedList
	/// </summary>
	/// <param name="value"></param>
	void pushFront(const AnyType& value);
	
	/// <summary>
	/// adds a new node to the end of the LinkedList
	/// </summary>
	/// <param name="value"></param>
	void pushBack(const AnyType& value);

	/// <summary>
	/// removes the node at the beginning of the LinkedList and returns the value
	/// </summary>
	/// <returns></returns>
	AnyType popFront();
	
	/// <summary>
	/// removes the node at the end of the LinkedList and returns the value
	/// </summary>
	/// <returns></returns>
	AnyType popBack();

	/// <summary>
	/// adds a new node at the given index
	/// </summary>
	/// <param name="value"></param>
	/// <param name="index"></param>
	/// <returns></returns>
	bool insert(const AnyType& value, int index);
	
	/// <summary>
	/// removes the first node with the given value
	/// </summary>
	/// <param name="value"></param>
	/// <returns></returns>
	bool remove(const AnyType& value);
	
	/// <summary>
	/// sets the given iterator to point to a node at the given index
	/// </summary>
	/// <param name="iter"></param>
	/// <param name="index"></param>
	/// <returns></returns>
	bool getData(Iterator<AnyType>& iter, int index);
	
	/// <summary>
	/// returns the amount of nodes in the LinkedList
	/// </summary>
	/// <returns></returns>
	const int getLength();
	
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
		/// first node in the link list
		/// </summary>
		Node<AnyType>* m_first;

		/// <summary>
		/// last node in the link list
		/// </summary>
		Node <AnyType>* m_last;

		/// <summary>
		/// the amount of nodes inside of the link list
		/// </summary>
		int m_nodeCount;











};

template<typename AnyType>
inline LinkedList<AnyType>::LinkedList()
{
	initialize();
}

template<typename AnyType>
inline LinkedList<AnyType>::LinkedList(const LinkedList<AnyType>& other)
{
	initialize();

	*this = other;

}


template<typename AnyType>
inline void LinkedList<AnyType>::initialize()
{
	m_first = nullptr;
	m_last = nullptr;
	m_nodeCount = 0;
}

template<typename AnyType>
inline void LinkedList<AnyType>::destroy()
{
	if (m_nodeCount == 0)
		return;

	for (int i = 0; i < m_nodeCount; i++)
	{
		popBack();
	}

	initialize();
}

template<typename AnyType>
inline Iterator<AnyType> LinkedList<AnyType>::begin() const
{
	return Iterator<AnyType>(m_first);
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
	return m_first->data;
}

template<typename AnyType>
inline AnyType LinkedList<AnyType>::last() const
{
	return m_last->data;
}

template<typename AnyType>
inline bool LinkedList<AnyType>::contains(const AnyType object) const
{
	return false;
}

template<typename AnyType>
inline bool LinkedList<AnyType>::isEmpty() const
{
	//if both first and last are null pointers then the node count would be 0 and the LinkedList is empty
	if (m_first == nullptr && m_last == nullptr)
	{
		std::cout << "LinkedList is empty" << std::endl;
		return true;
	}
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

	//check if the only node is the new node we just made and if so make it the last as well as the first. This will also make both of new node's next and previous null pointers
	if (m_nodeCount == 0)
		m_last = newNode;
	//increase the amount of nodes within the list being tracked
	m_nodeCount++;
}

template<typename AnyType>
inline void LinkedList<AnyType>::pushBack(const AnyType& value)
{
	//create a new node that contains the given value 
	Node<AnyType>* newNode = new Node<AnyType>(value);

	//increase the amount of nodes within the list being tracked
	m_nodeCount++;

	//check if the only node is the new node we just made and if so make it the first as well as the last. This will also make both of new node's next and previous null pointers
	if (!m_last)
	{
		m_last = newNode;
		m_first = newNode;
		return;
	}

	//set the last's next to be the new node
	m_last->next = newNode;

	//set new node's previous to be last
	newNode->previous = m_last;

	//set the last node to be the new node
	m_last = newNode;

}

template<typename AnyType>
inline AnyType LinkedList<AnyType>::popFront()
{
	//if list is empty nothing to pop so dont't run code
	if (m_nodeCount == 0)
		return AnyType();

	//save data inside of first in local variable
	AnyType value = m_first->data;
	
	//make the next of first the new first
	m_first = m_first->next;

	//
	if (!m_first->previous)
	{
		//delete the old first aka new first's previous 
		delete m_first->previous;

		//make the new first's previous null pointer
		m_first->previous = nullptr;
	}
	//reduce the nodecount by 1
	m_nodeCount--;

	//return the data that was in the previous first
	return value;
}

template<typename AnyType>
inline AnyType LinkedList<AnyType>::popBack()
{
	//if list is empty nothing to pop so dont't run code
	if (m_nodeCount == 0)
		return AnyType();

	//save data inside of first in local variable
	AnyType value = m_last->data;

	//make the previous of last the new last
	m_last = m_last->previous;

	if (!m_last->next)
	{
		//delete the old last aka new last's next
		delete m_last->next;

		//make the new last's next null pointer
		m_last->next = nullptr;
	}
	//reduce the nodecount by 1
	m_nodeCount--;

	//return the data that was in the previous last
	return value;
}

template<typename AnyType>
inline bool LinkedList<AnyType>::insert(const AnyType& value, int index)
{
	//check if the iindex is within the bounds of the list
	if(index < 0 || index >= m_nodeCount)
	return false;

	//if the list is empty...
	if (m_nodeCount == 0)
	{
		//...re-use the logivc from pushback to add it to the list
		pushBack(value);
		return true;
	}

	if (index == 0)
		pushFront(value);

	
	//
	Node<AnyType>* newNode = new Node<AnyType>(value);

	Node<AnyType>*iter = m_first;

	for (int i = 0; i <= index; i++)
	{
		if (iter->next == nullptr)
			break;

		iter = iter->next;
	}

	newNode->next = iter;
	newNode->previous = iter->previous;
	
	//new node's previous' next is new node
	newNode->previous->next = newNode;

	iter->previous = newNode;

	m_nodeCount++;

	return true;
}

template<typename AnyType>
inline bool LinkedList<AnyType>::remove(const AnyType& value)
{

	Node<AnyType>* iter = m_first;

	for (int i = 0; i <= m_nodeCount; i++)
	{
		if (iter == nullptr)
			return false;

		if (iter->data == value)
			break;

		iter = iter->next;
	}
	if (iter == m_first)
	{
		popFront();
		return true;
	}
	if (iter == m_last)
	{
		popBack();
		return true;
	}
	

	iter->next->previous = iter->previous;
	iter->previous->next = iter->next;

	delete iter;

	m_nodeCount--;

	return true;
}

template<typename AnyType>
inline void LinkedList<AnyType>::print() const
{
	for (Iterator <AnyType> iter = begin(); iter != end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
}

template<typename AnyType>
inline bool LinkedList<AnyType>::getData(Iterator<AnyType>& iter, int index)
{
	return false;
}

template<typename AnyType>
inline const int LinkedList<AnyType>::getLength()
{
	return m_nodeCount;
}

template<typename AnyType>
inline void LinkedList<AnyType>::operator=(const LinkedList<AnyType>& otherLinkedList)
{
	//need to pop the the old list and take the data and put it in the new list.
	for (int i = 0; i < otherLinkedList.m_nodeCount; i++)
	{
		insert(i);
	
	}

}

template<typename AnyType>
inline void LinkedList<AnyType>::sort()
{
}

//need to finish constructor
//need to finish getdata
//need to finish sort
//need to finish contains
//need to finish operator =
//need to test all functions
