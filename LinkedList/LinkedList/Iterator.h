#pragma once
#include "Node.h"
template<typename AnyType>
class Iterator
{

public:

	Iterator<AnyType>();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="node"></param>
	Iterator<AnyType>(Node<AnyType>* node);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	Iterator<AnyType> operator ++();
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	Iterator<AnyType> operator --();
	
	/// <summary>
	///
	/// </summary>
	/// <param name="iter"></param>
	/// <returns></returns>
	const bool operator ==(const Iterator<AnyType>& iter);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="iter"></param>
	/// <returns></returns>
	const bool operator !=(const Iterator<AnyType>& iter);
	
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	AnyType operator *();




private:

	/// <summary>
	/// The node the iterator is current looking at.
	/// </summary>
	/// <typeparam name="AnyType"></typeparam>
	Node<AnyType>* m_current


};

template<typename AnyType>
inline Iterator<AnyType>::Iterator()
{
	m_current = nullptr;
}

template<typename AnyType>
inline Iterator<AnyType>::Iterator(Node<AnyType>* node)
{
	m_current = node;
}

template<typename AnyType>
inline Iterator<AnyType> Iterator<AnyType>::operator++()
{
	if (m_current != nullptr)
	{
		Iterator<AnyType> iter = Iterator<AnyType>(m_current->next);
		m_current = m_current->next;
		return iter;
	}

	Iterator<AnyType> iter = Iterator<AnyType>(nullptr);
	return iter;

}

template<typename AnyType>
inline Iterator<AnyType> Iterator<AnyType>::operator--()
{
	if (m_current != nullptr)
	{
		Iterator<AnyType> iter = Iterator<AnyType>(m_current->previous);
		m_current = m_current->previous;
		return iter;
	}

	Iterator<AnyType> iter = Iterator<AnyType>(nullptr);
	return iter;
}

template<typename AnyType>
inline const bool Iterator<AnyType>::operator==(const Iterator<AnyType>& iter)
{
	return m_current == iter.m_current;
	//below would equal the same thing as above
	//if(this->m_current == iter.m_current)
	//return true;
}

template<typename AnyType>
inline const bool Iterator<AnyType>::operator!=(const Iterator<AnyType>& iter)
{
	return m_current != iter.m_current;
}

template<typename AnyType>
inline AnyType Iterator<AnyType>::operator*()
{
	
	return m_current->data;
}
