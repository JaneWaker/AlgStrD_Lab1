#include "List.h" 
#include <iostream>

using namespace std;

void List::push_back(int new_elem) //addition to the end of the list
{
	if (size != 0) {
		last->next = new Node(new_elem);
		last = last->next;
	}
	else { 
		head = new Node(new_elem);
		last = head;
	}
	size++;
}

void List::push_front(int new_elem) { //addition to the top of the list
	if (size != 0) { 
		head = new Node(new_elem, head);
	} 
	else { 
		head = new Node(new_elem);
		last = head;
	} 
	size++; 
}

void List::pop_back() { //deleting the last element
	if (IsEmpty()) {
		throw out_of_range("You are trying to remove an item from an empty list"); 
		return; 
	}
	else {
		if (size == 1) {
			delete head;
			head = nullptr;
			last = nullptr;
		}
		else {
			Node* cur = head;
			while (cur->next != last) {
				cur = cur->next;
			}
			cur->next = nullptr;
			delete last;
			last = cur;
		}
		size--;
	}
} 

void List::pop_front() { //deleting of the first element
	if (IsEmpty()) {
		throw out_of_range("You are trying to remove an item from an empty list");
		return;
	}
	else {
		if (size == 1) {
			delete head;
			head = nullptr;
			last = nullptr;
		}
		else {
			Node* cur = head;
			head = cur->next; 
			delete cur;
		}
		size--;
	}
}

void List::insert(int insert_data, size_t index) { //adding an element by index (insert before the element which was previously available by this index)
	if (index == 0) { 
		push_front(insert_data);
	}
	else if (index >= size) { 
		throw out_of_range("Index is greater than list size"); 
	}
	else {
		Node* cur = head; 
		for (int i = 0; i < index; i++) {
			cur = cur->next; 
			} 
		Node* insert_Node = new Node(insert_data, cur->next);
		cur->next = insert_Node; 
		size++;
	}
}

int List::at(size_t n) { //retrieve an element by index
	if (n >= size) { 
		throw out_of_range("Index is greater than list size"); 
	}
	else { 
		Node* cur = head; 
		for (int i = 0; i < n; i++) {
			cur = cur->next;
		}
		return cur->data; 
	}
}

void List::remove(size_t index) { //item deletion by index
	if (index >= size) { 
		throw out_of_range("Index is greater than list size"); 
	} 
	if (index == 0) {
		pop_front();
	} 
	else { 
		Node* cur = head; 
		for (int i = 0; i < index; i++) {
			cur = cur->next;
		}
		Node* delete_elem = cur->next; 
		cur->next = delete_elem->next;
		delete delete_elem;
		size--; 
	}
} 

void List::print_to_console() { //output the list elements to the console via delimiter
	Node* cur = head; 
	while (cur->next != last) { 
		cout << cur->data << ' '; 
		cur = cur->next; 
	} 
	cout << endl;
} 

void List::clear() { //deleting of all the elements of the list
	if (size == 0) { 
		throw out_of_range("You are trying to remove an item from an empty list"); 
	} 
	Node* cur = new Node;
	cur = head;
	while (cur != NULL) {
		head = cur;
		cur = cur->next;
		delete head;
		size--;
	}
	delete cur;
	head = NULL;
	last = head;
} 

void List::set(int transmittable_elem, size_t index) { //replacement of the element by the index by the passed element
	if (index >= size) {
		throw out_of_range("Index is greater than list size");
	}
	Node* cur = head;
	for (int i = 0; i < index; i++) {
		cur = cur->next;
	}
	cur->data = transmittable_elem;
}

bool List::IsEmpty() { //check for emptiness of the list
	return (head == nullptr);
}

void List::insert(List* List2, size_t index) { //insertion of another list in the list, starting from the index (14 function)
	if (index > 0) {
		for (int i = (*List2).get_size() - 1; i >= 0; i--) {
			insert((*List2).at(i), index - 1);
		}
	} else 
		for (int i = (*List2).get_size() - 1; i >= 0; i--) { 
			push_front((*List2).at(i)); 
		}
}

List::~List() { //clear
	clear();
}