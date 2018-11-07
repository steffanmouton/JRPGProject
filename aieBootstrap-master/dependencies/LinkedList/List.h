#pragma once
#include "Iterator.h"

template <typename T>
class LinkedListType
{
protected:
	//List only tracks the number of nodes and pointers to first and last node
	int count;
	Node<T>* first;
	Node<T>* last;

private:
	
	void CopyList(const LinkedListType<T>&);

public:
	const LinkedListType<T>& operator=(const LinkedListType<T>&);
	void InitializeList();
	bool IsEmptyList() const;
	void Print() const;
	int Length() const;
	void DestroyList();
	T Front() const;
	T Back() const;
	virtual bool Search(const T&) const = 0;
	virtual void InsertFirst(const T&) = 0;
	virtual void InsertLast(const T&) = 0;
	virtual void DeleteNode(const T&) = 0;
	Iterator<T> Begin();
	Iterator<T> End();
	LinkedListType();
	LinkedListType(const LinkedListType<T>&);
	~LinkedListType();
};

//Make one list become a copy of another at new memory location
template<typename T>
void LinkedListType<T>::CopyList(const LinkedListType<T>& original)
{
	this->DestroyList();

	Node<T>* temp = original.first;
	while (temp != nullptr)
	{
		this->InsertLast(temp->info);
		temp = temp->next;
	}
	
}

//Assignment operator performs the CopyList function on another
template<typename T>
const LinkedListType<T>& LinkedListType<T>::operator=(const LinkedListType<T>& rhs)
{
	this->CopyList(rhs);
	return *this;
}

//Initializes a list with 0 node count and first and last pointers to null
template<typename T>
void LinkedListType<T>::InitializeList()
{
	count = 0;
	first = nullptr;
	last = nullptr;
	first->next = last;
}

//boolean check if a list has any nodes
template<typename T>
bool LinkedListType<T>::IsEmptyList() const
{
	return (count == 0);
}

//Iterates through a list, printing the saved "Info" variable of each node
template<typename T>
void LinkedListType<T>::Print() const
{
	if (IsEmptyList())
	{
		std::cout << "List is empty" << std::endl;
		return;
	}
	else
	{
		Node<T>* printer = first;
		while (printer != nullptr)
		{
			std::cout << printer->info << std::endl;
			printer = printer->next;
		}
	}
	std::cout << std::endl;
}

//returns length of list by its count
template<typename T>
int LinkedListType<T>::Length() const
{
	return this->count;
}

//Destroys all the nodes in a list. 
template<typename T>
void LinkedListType<T>::DestroyList()
{
	if (IsEmptyList())
	{
		return;
	}
	else
	{
		Node<T>* destroyer(first);
		while (destroyer != nullptr)
		{
			Node<T>* trail = destroyer;
			destroyer = destroyer->next;
			delete trail;
			this->count--;
		}
	}
}

//Returns the info at the front node of a list
template<typename T>
T LinkedListType<T>::Front() const
{
	return first->info;
}

//Returns the info at the back node of a list
template<typename T>
T LinkedListType<T>::Back() const
{
	return last->info;
}

//Return an iterator with Current set to first node of list
template<typename T>
Iterator<T> LinkedListType<T>::Begin()
{
	return Iterator<T>(first);
}

//Return an iterator with Current set to last node of list
template<typename T>
Iterator<T> LinkedListType<T>::End()
{
	return Iterator<T>(last);
}

//Constructor for a new LinkedList
template<typename T>
LinkedListType<T>::LinkedListType()
{
	count = 0;
	first = nullptr;
	last = nullptr;
}

//Constructor for a LinkedList with a passed-in Link
template<typename T>
LinkedListType<T>::LinkedListType(const LinkedListType<T>& original)
{
	this->CopyList(original);
}

//Destructor for a LinkedList
template<typename T>
LinkedListType<T>::~LinkedListType()
{
	this->DestroyList();
}
