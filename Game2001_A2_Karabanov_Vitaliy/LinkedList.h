#pragma once
#include <cassert>
//////////////////////////////////////////////////////////////////
//               template class declaration
//////////////////////////////////////////////////////////////////
template <class T> class LinkedIterator;
template <class T> class LinkedList;
template <class T> class PriorQ;
//////////////////////////////////////////////////////////////////
//                        LinkedNode 
//////////////////////////////////////////////////////////////////
template <class T>

class LinkedNode
{
private:
	T m_data;
	LinkedNode* m_next;
	LinkedNode* m_previous;
public:
	friend class LinkedIterator <T>;
	friend class LinkedList <T>;
};

//////////////////////////////////////////////////////////////////
//                         LinkedIterator
//////////////////////////////////////////////////////////////////
template <class T>

class LinkedIterator
{
private:
	LinkedNode<T>* m_node; //pointer to a node in the linked list
public:
	friend class LinkedList <T>;
	LinkedIterator()//constr
	{
		m_node = nullptr;
	}
	~LinkedIterator() {}//destr

	// -------------OVERLOADED OPERATORS-------------------
	//Assignment operator ( = )
	void operator=(LinkedNode<T>* node)
	{
		m_node = node;
	}
	// Dereferencing operator (*)
	T& operator*()
	{
		assert(m_node != nullptr);
		return m_node->m_data;
	}
	// Incremental operator - move the iterator to the next node
	// Prefix
	void operator++()
	{
		assert(m_node != nullptr);
		m_node = m_node->m_next;
	}
	// Postfix
	void operator++(int)	// Postfix
	{
		assert(m_node != nullptr);
		m_node = m_node->m_next;
	}
	// Decremental Operators - move the iterator to the prev node
	// Prefix
	void operator--()
	{
		assert(m_node != nullptr);
		m_node = m_node->m_previous;
	}
	// Postfix 
	void operator--(int)
	{
		assert(m_node != nullptr);
		m_node = m_node->m_previous;
	}
	// Comparison Operator (!= & ==)
	bool operator!=(LinkedNode<T>* node)
	{
		return (m_node != node);
	}
	bool operator==(LinkedNode<T>* node)
	{
		return (m_node == node);
	}
	LinkedNode<T>* GetNode()
	{
		return m_node;
	}

};
//////////////////////////////////////////////////////////////////
//                         Linked List 
//////////////////////////////////////////////////////////////////
template <class T>

class LinkedList
{
private:
	short m_size;
	LinkedNode<T>* m_rootNode; // the first node in linked list
	LinkedNode<T>* m_lastNode;
public:

	LinkedList() :

		m_size(0),
		m_rootNode(nullptr),
		m_lastNode(nullptr) {}

	~LinkedList()
	{
		while (m_rootNode)
		{
			Pop();
		}
	}

	//Positioning Funcs
	/////////////////////////////////////////////////////////////  //////////////////////////
	LinkedNode<T>* Begin()										   //////////////////////////
	{															   //////////////////////////
		assert(m_rootNode != nullptr);							   //////////////////////////
		return m_rootNode;										   //////////////////////////
	}															   //////////////////////////
	LinkedNode<T>* End()											   //////////////////////////
	{															   //////////////////////////
		return nullptr;											   //////////////////////////
	}															   //////////////////////////
	LinkedNode<T>* Last()											   //////////////////////////
	{															   //////////////////////////
		assert(m_lastNode != nullptr);							   //////////////////////////
		return m_lastNode;										   //////////////////////////
	}															   //////////////////////////
	/////////////////////////////////////////////////////////////


	// Main Funcs of the linked list
	/////////////////////////////////////////////////////////////

	void Pop()//Pop front basically
	{
		assert(m_rootNode != nullptr);
		LinkedNode<T>* temp = m_rootNode;
		m_rootNode = m_rootNode->m_next;

		if (m_rootNode != nullptr)
			m_rootNode->m_previous = nullptr;
		else
			m_lastNode = nullptr;

		delete temp;
		temp = nullptr;

		m_size = (m_size == 0 ? m_size : m_size - 1);
	}


	void PushBack(T newData)
	{
		LinkedNode<T>* node = new LinkedNode<T>;

		assert(node != nullptr);
		node->m_data = newData;
		node->m_next = nullptr;
		node->m_previous = nullptr;

		if (m_lastNode != nullptr)
		{
			m_lastNode->m_next = node;
			node->m_previous = m_lastNode;
		}
		else  //no items in list
			m_rootNode = node;

		m_lastNode = node;
		m_size++;
	}
	short getSize()
	{
		return m_size;
	}
};
//////////////////////////////////////////////////////////////////
//                        Priority Qeue
//////////////////////////////////////////////////////////////////
template <class T>

class PriorQ
{
private:

public:
	PriorQ()
	{
	}
	~PriorQ() {}
	//                  PRIORITY QUEUE FUNCTIONS
	/////////////////////////////////////////////////////////////////
};