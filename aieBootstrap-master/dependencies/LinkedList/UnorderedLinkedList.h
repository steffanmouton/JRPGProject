#pragma once
#include "List.h"
#include <iostream>

template<typename T>
class UnorderedLinkedList : public LinkedListType<T>
{
public:
	bool Search(const T& item) const override
		// goes through every node in list and returns true if item is found
	{
		Node<T>* check = this->first;
		for (int i = 0; i < this->count; i++) 
		{
			if (check->info == item)
			{
				return true;
			}
			else
			{
				check = check->next;
			}
		}

		return false;
	}
	void InsertFirst(const T& item) override //Insert new node at first place in list
	{
		this->count++;
		Node<T>* temp = new Node<T>{ item, this->first };				
		this->first = temp;		

		if (count == 1)
		{
			this->last = temp;
		}
	}
	void InsertLast(const T& item) override //Insert a new node at the last place in list
	{
		this->count++;
		Node<T>* temp = new Node<T>{ item, this->first };

		if (this->count == 1) //if one item in list, set first and last to that item
		{
			this->last = temp;
			this->first = temp;
		}
		else if (this->count == 2) //if two items, set original to first, new to last
		{
			temp->next = nullptr;
			this->last= temp;
			this->first->next = temp;
			
		}
		else //if more than two items, only adjust last to be temp
		{
			temp->next = nullptr;
			this->last->next = temp;
			this->last = temp;
		}
	}
	void DeleteNode(const T& item) override
	{
		//create lead and trailing pointers
		Node<T>* lead = this->first;
		Node<T>* trail = this->first;

		
		if (this->count == 0) //if list is empty, say so
		{
			std::cout << "List is empty" << std::endl;
		}
		//if only one node, reset first and last pointers to null
		else if (this->count == 1 && lead->info == item) 
		{
			delete lead;
			this->first = nullptr;
			this->last = nullptr;
			this->count--;
		}
		//if more than one node, check to see if node containing desired value
		//is first, last, or in middle of list. Then delete and readjust pointers
		//accordingly
		else if (this->count > 1)
		{
			for (int i = 0; i < this->count; i++)
			{
				lead = lead->next;
				if (trail->info == item && i == 0)
				{
					this->first = lead;
					delete trail;
					this->count--;
					break;

				}
				else if (lead->info == item && i >= 0 && i < this->count)
				{
					trail->next = lead->next;
					delete lead;
					this->count--;
					break;
				}
				else if (lead->info == item && i == this->count)
				{
					trail->next = nullptr;
					this->last = trail;
					delete lead;
					this->count--;
					break;
				}
				trail = trail->next;
			}
		}
	}
};