#pragma once

template<typename AnyType>
class Node
{

public:

	Node();

	/// <summary>
	/// A node is part of a Linked List. It holds a source of data, the next node in the List, and it's previous node in the List
	/// </summary>
	/// <param name="dataT">the data/information that this intance of a node holds within it.</param>
	Node(AnyType value);

	/// <summary>
	/// The pointer to the next Node in the Linked List in comparison to this instance of a Node
	/// </summary>
	Node<AnyType>* next;

	/// <summary>
	/// The pointer to the previous Node in the Linked List in comparison to this instance of a Node
	/// </summary>
	Node<AnyType>* previous;

	/// <summary>
	/// The information that this instance of a Node is holding within it.
	/// </summary>
	AnyType data;


};

template<typename AnyType>
inline Node<AnyType>::Node()
{
	previous = nullptr;
	next = nullptr;

}

template<typename AnyType>
inline Node<AnyType>::Node(AnyType value)
{
	data = value;
	previous = nullptr;
	next = nullptr;
}
