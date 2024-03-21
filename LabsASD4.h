#pragma once

#include <iostream>
#include <vector>
#include <exception>

using namespace std;

struct Node {
	int _data;
	Node* _left;
	Node* _right;
	Node() : _data(0), _left(nullptr), _right(nullptr) {};
	Node(int data, Node* left, Node* right) : _data(data), _left(left), _right(right) {};
	Node(int data) : _data(data), _left(nullptr), _right(nullptr) {};
	
	void print() const {
		if (this->_left) {
			cout << '(';
			this->_left->print();
			cout << ')';
		}
		cout << this->_data;
		if (this->_right) {
			cout << '(';
			this->_right->print();
			cout << ')';
		}
	}
};

class Tree {
private:
	Node* _root;

	Node* copy(Node* ptr) {
		if (ptr == nullptr) {
			return nullptr;
		}
		auto tmp = new Node(ptr->_data);
		tmp->_left = copy(ptr->_left);
		tmp->_right = copy(ptr->_right);
		return tmp;
	}
	
	void delete_tree(Node* ptr) {
		if (ptr == nullptr) {
			return;
		}
		delete_tree(ptr->_left);
		delete_tree(ptr->_right);
		delete ptr;
	}
	
	int height(Node* ptr) {
		if (ptr == nullptr) {
			return 0;
		}
		return std::max(height(ptr->_left), height(ptr->_right)) + 1;
	}
	
	Node* min(Node* ptr) {
		while (ptr->_left != nullptr) {
			ptr = ptr->_left;
		}
		return ptr;
	}
	
	void to_vector(Node* ptr, vector<int>& vec) {
		if (ptr == nullptr) {
			return;
		}
		vec.push_back(ptr->_data);
		to_vector(ptr->_left, vec);
		to_vector(ptr->_right, vec);

	}

	Node* erase(Node* ptr, const int value) {
		if (ptr == nullptr) {
			return nullptr;
		}
		if (value < ptr->_data) {
			ptr->_left = erase(ptr->_left, value);
		}
		else if (value > ptr->_data) {
			ptr->_right = erase(ptr->_right, value);
		}
		else {
			if (ptr->_left == nullptr || ptr->_right == nullptr) {
				Node* tmp;
				if (ptr->_left != nullptr) {
					tmp = ptr->_left;
				}
				else {
					tmp = ptr->_right;
				}
				if (tmp == nullptr) {
					tmp = ptr;
					ptr = nullptr;
				}
				else {
					*ptr = *tmp;
				}
				delete tmp;
			}
			else {
				auto tmp = min(ptr->_right);
				ptr->_data = tmp->_data;
				ptr->_right = erase(ptr->_right, tmp->_data);
			}

		}
		return ptr;
	}
	
	Node* insert(Node* ptr, const int value) {
		if (ptr == nullptr) {
			return new Node(value);
		}
		if (value < ptr->_data) {
			ptr->_left = insert(ptr->_left, value);
		}
		else if (value > ptr->_data) {
			ptr->_right = insert(ptr->_right, value);
		}
		else {
			return ptr;
		}
		return ptr;
	}
	
	bool contains(Node* ptr, const int value) {
		if (ptr == nullptr) {
			return false;
		}
		if (ptr->_data == value) {
			return true;
		}
		if (value > ptr->_data) {
			return contains(ptr->_right, value);
		}
		else {
			return contains(ptr->_left, value);
		}
	}

public:
	Tree() : _root(nullptr) {};
	Tree(Tree& other) {
		_root = copy(other._root);
	}
	~Tree() {
		delete_tree(_root);
		_root = nullptr;
	}

	void operator=(Tree& other) {
		delete_tree(_root);
		_root = copy(other._root);
	}
	
	int min() {
		return min(_root)->_data;
	}
		
	void clear() {
		delete_tree(_root);
		_root = nullptr;
	}
	
	vector<int> to_vector() {
		vector<int> vec;
		to_vector(_root, vec);
		return vec;
	}

	bool insert(const int value) {
		if (contains(value)) {
			return false;
		}
		else {
			_root = insert(_root, value);
			return true;
		}
	}
	
	void print() const {
		if (this->_root)
			this->_root->print();
		else
			cout << "The set is empty";
	}
	
	bool contains(const int value) {
		return contains(_root, value);
	}
	
	bool erase(const int value) {
		if (!contains(value)) {
			return false;
		}
		else {
			_root = erase(_root, value);
			return true;
		}
	}
};

size_t lcg() {
	static size_t x = 0;
	x = (1021 * x + 24631) % 116640;
	return x;
}

vector<int> DuplicatesVector(vector<int>& input) {
	Tree uniqueTree;
	Tree duplicateTree;
	vector<int> duplicates;

	for (int value : input) {
		if (uniqueTree.contains(value)) {
			if (!duplicateTree.contains(value)) {
				duplicateTree.insert(value);
				duplicates.push_back(value);
			}
		}
		else {
			uniqueTree.insert(value);
		}
	}

	return duplicates;
}
