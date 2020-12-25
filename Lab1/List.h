#pragma once
#include <iostream> 
class List
{
private:
	class Node
	{
	public:
		Node(int data = 0, Node* next = nullptr)
		{
			this->data = data;
			this->next = next;
		};

		~Node() {};
		int data;
		Node* next;
	};

	Node* head;
	Node* last;
	size_t size;
 
public:
	List(Node* head = NULL, Node* last = NULL)
	{
		size = 0;
		this->head = head;
		this->last = last;
	}
	void push_back(int); //addition to the end of the list
	void push_front(int); //addition to the top of the list
	void pop_back(); //deleting the last element
	void pop_front(); //deleting of the first element
	void insert(int, size_t); //adding an element by index (insert before the element which was previously available by this index)
	int at(size_t); //retrieve an element by index
	void remove(size_t); //item deletion by index
	size_t get_size() { //getting the list size
		return size; 
	}
	void print_to_console(); //output the list elements to the console via delimiter
	void clear(); //deleting of all the elements of the list
	void set(int, size_t); //replacement of the element by the index by the passed element
	bool IsEmpty(); //check for emptiness of the list
	void insert(List*, size_t); //insertion of another list in the list, starting from the index (14 function)
	~List();
};
