#pragma once

template <typename T>
struct Node
{
	//A node holds only two variables. Info of a given type,
	//and a pointer to the next node of the list.
	T info;
	Node<T>* next;
};