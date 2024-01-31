#pragma once
#include <iostream>
#include "Iterator.h"
template<typename AnyType>
class LinkedList
{
public:

	LinkedList();
	/// <summary>
	/// 
	/// </summary>
	/// <param name="other"></param>
	LinkedList(const LinkedList<AnyType>& other);

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
	void initialize();
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	const bool isEmpty();
	
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
	Node m_first;
	
	/// <summary>
	/// 
	/// </summary>
	Node m_last;
	
	/// <summary>
	/// 
	/// </summary>
	int m_nodeCount;







};

template<typename AnyType>
inline LinkedList<AnyType>::LinkedList(const LinkedList<AnyType>& other)
{
	*this = other;
}
