#include <iostream>
#include "list.h"

using namespace std;



/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, const Node* nd) {
	os << nd->data << endl;
	return os;
}


/*
 * Add a node to the end of a list.
 * */
void add_at_end(Node*& head, int d) {
	Node* temp = new Node(d, nullptr);
	Node* counter = head;
	if (counter != nullptr) {
		while (counter->next != nullptr) {
			counter = counter->next;
		}
		counter->next = temp;
	}
	else {
		head=temp;
	}

	
}


/*
 * Given the head of a list, print the whole thing.
 * Let's do this recursively!
 * */
void print_list(ostream& os, const Node* curr) {
	while (curr != nullptr) {
		cout << curr->data << ' ';
		curr = curr->next;
	}
	cout << endl;
	
}

/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int d) {
	Node* temp = new Node(d,head);
	head = temp;
	
}


/*
 * Get the last node of a list.
 * */
Node* last(Node* head) {
	if (head == nullptr) {
		return nullptr;
	}
	else {
		if (head->next == nullptr) {
			return head;
		}
		else {
			return last(head->next);
		}
	}
}

bool del_head(Node*& head) {
	if (head != nullptr) {
		Node* second = head->next;
		delete head;
		head = second;
		return true;
	}
	else {
		return false;
	}
}

bool del_tail(Node*& head) {
	if (head == nullptr) {
		return false;
	}
	else if (head->next == nullptr) {
		delete head;
		head = nullptr;
		return true;
	}
	else {
		return del_tail(head->next);
	}
}

Node* duplicate(Node* node) {
	if (node == nullptr) {
		return nullptr;
	}
	else {
		return new Node(node->data, duplicate(node->next));
		
	}
}

Node* reverse(Node* curr, Node* new_next) {
	if (curr == nullptr) {
		return new_next;
	}
	else {
		return reverse(curr->next, new Node(curr->data, new_next));
	}

}

Node* join(Node*& List1, Node* List2) {
	Node* lastl1 = last(List1);
	lastl1->next = new Node(List2->data, List2->next);
	return List1;
}