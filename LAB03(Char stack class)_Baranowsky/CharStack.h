#pragma once
class Stack
{
public:
	Stack();
	~Stack();

	void Push_front(char);
	void Push_back(char);
	void Pop_front();
	void Pop_back();
	void Insert(char, int);
	void RemoveAt(int);
	int GetSize();
	void Clear();
	void Display();

	char& operator[](const int index);

private:
	class Node
	{
	public:
		Node* next;
		char data;
		Node(char data = char(), Node* next = nullptr)
		{
			this->next = next;
			this->data = data;
		}
	};
	int Size;
	Node* head;
};