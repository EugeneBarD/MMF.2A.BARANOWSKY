#include "CharStack.h"
#include <iostream>

using namespace std;

Stack::Stack()
{
	Size = 0;
	head = nullptr;
}

Stack::~Stack()
{
	this->Clear();
}

void Stack::Push_front(char symbol)
{
	head = new Node(symbol, head);
	Size++;
}

void Stack::Push_back(char symbol)
{
	if (head == nullptr)
	{
		head = new Node(symbol);
	}
	else
	{
		Node* current = this->head;

		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = new Node(symbol);
	}

	Size++;
}

void Stack::Pop_front()
{
	Node* buffNode = head;

	head = head->next;

	delete buffNode;

	Size--;
}

void Stack::Pop_back()
{
	this->RemoveAt(Size - 1);
}

void Stack::Insert(char symbol, int index)
{
	if (index == 0) 
	{
		this->Push_front(symbol);
	}
	else
	{
		Node* previous = head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->next;
		}

		Node* newNode = new Node(symbol, previous->next);
		previous->next = newNode;

		Size++;
	}
}

void Stack::RemoveAt(int index) 
{
	if (index == 0)
	{
		this->Pop_front();
	}
	else
	{
		Node* previous = head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->next;
		}

		Node* removing = previous->next;
		previous->next = removing->next;

		delete removing;

		Size--;
	}
}

int Stack::GetSize()
{
	return this->Size;
}

char& Stack::operator[](const int index)
{
	int counter = 0;
	Node* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->next;
		counter++;
	}
}

void Stack::Clear() 
{
	while (Size)
	{
		this->Pop_front();
	}
}

void Stack::Display()
{
	cout << "Stack:\n";
	Node* buffNode = head;

	for (int i = 0; i < Size; i++)
	{
		cout << buffNode->data << (i == Size - 1 ? "" : " ");

		buffNode = buffNode->next;
	}
}