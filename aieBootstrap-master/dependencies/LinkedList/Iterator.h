#pragma once
#include "Node.h"

template <typename T>
class Iterator
{
private:
	Node<T> *current;

public:
	Iterator();
	Iterator(Node<T>*);
	//make iterator move to NEXT
	Iterator<T> operator++();
	//dereference information of node
	T operator*();
	bool operator==(const Iterator<T>&) const;
	bool operator!=(const Iterator<T>&) const;
};

template<typename T>
Iterator<T>::Iterator()
{
	//Constructor, setting an iterator pointing to current
	current = nullptr;
}

template<typename T>
Iterator<T>::Iterator(Node<T>* node)
{
	//Constructor, setting iterator pointing to a given node
	current = node;
}

template<typename T>
Iterator<T> Iterator<T>::operator++()
{
	//make an iterator move to the next node in a list
	current = current->next;
	return *this;
}

template<typename T>
T Iterator<T>::operator*()
{
	//overloading dereference operator, returns the info at pointed node
	return this->current->info;
}

template<typename T>
bool Iterator<T>::operator==(const Iterator<T>& rhs) const
{
	//compares iterators by the info of the nodes they point to
	return (*this == *rhs);
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator<T>& rhs) const
{
	//compares iterators by the info of the nodes they point to
	return (*this != *rhs);
}