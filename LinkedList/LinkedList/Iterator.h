#pragma once
#include <iostream>
#include "Node.h"
template<typename AnyType>
class Iterator
{

public:

	Iterator();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="node"></param>
	Iterator(Node<AnyType>* node);

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
	/// 
	/// </summary>
	/// <typeparam name="AnyType"></typeparam>
	Node m_current


};






