#ifndef BST_H
#define BST_H

#include <iostream>

void indent(int level) {
	// indent more at each level:
	for (int i = 0; i < level; i++) std::cout << "  ";
}

template <typename T>
class Bst {
	friend void print_bst(const Bst<T>& bst, int level = 0) {
		indent(level);
		level++;

		std::cout << "data: " << bst.data << std::endl;
		indent(level + 1);
		std::cout << "left: ";

		if (!bst.left) std::cout << "nullptr\n";
		else {
			std::cout << "\n";
			indent(level);
			print_bst(*bst.left, level);
		}
		indent(level + 1);
		std::cout << "right: ";
		if (!bst.right) std::cout << "nullptr\n";
		else {
			std::cout << "\n";
			indent(level);
			print_bst(*bst.right, level);
		}
		std::cout << std::endl;
	}

public:
	Bst(T d, Bst* p = nullptr, Bst* l = nullptr, Bst* r = nullptr)
		: data(d), parent(p), left(l), right(r) {}

	Bst<T>* insert(const T d) {
		if (d <= data) {
			if (left) {
				left->insert(d);
			}
			else {
				Bst<T>* node = new Bst<T>(d);
				left = node;
				node->parent = left;
				return node;
			}
		}
		else {
			if (right) {
				right->insert(d);
			}
			else {
				Bst<T>* node = new Bst<T>(d);
				right = node;
				node->parent = right;
				return node;
			}
		}
	
	}

	T get_val() const {
		return data;
	}

	T min() {
		if (left) {
			return left->min();
		}
		else {
			return data;
		}
	}
	
	T max() {
		if (right) {
			return right->max();
		}
		else {
			return data;
		}
	}


	Bst<T>* search(const T val) {
		if (data == val) {
			return this;
		}
		else if (val < data) 
		{
			if (!left) {
				return nullptr;
			}
			else {
				return left->search(val);
			}
		}
		else {
			if (!right) {
				return nullptr;
			}
			else {
				return right->search(val);
			}
		}
	}

	Bst<T>* predecessor(const T val) {
		Bst<T>* Node = search(val);
		if (Node->left) {
			return search(Node->left->max());
		}
		else {
			parent = Node->parent;
			while (parent) {
				if (parent->data < Node->data) {
					break;
				}
				parent = parent->parent;
			}
			return parent;
		}
	}

	Bst<T>* successor(const T val) {
		Bst<T>* Node = search(val);
		if (Node->right) {
			return search(Node->right->min());
		}
		else {
			parent = Node->parent;
			while (parent) {
				if (parent->data > Node->data) {
					break;
				}
				parent = parent->parent;
			}
			return parent;
		}
	}

private:
	T data;
	Bst* parent;
	Bst* left;
	Bst* right;
};
#endif
