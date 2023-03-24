#pragma once
#include <iostream>
#include <vector>

template <class T>
class BinarySearchTree
{
private:
	template <class T>
	struct Node {
		T key_;
		Node<T>* left_;
		Node<T>* right_;
		Node<T>* p_;
		Node(T key, Node* left = nullptr, Node* right = nullptr, Node* p = nullptr) :
			key_(key), left_(left), right_(right), p_(p)
		{ }
	};
	Node<T>* root_;
	Node<T>* iterativeSearchNode(const T& key) const;
	void printNode(std::ostream& out, Node<T>* node, std::string indent, bool isLast) const;
	int getCount(const Node<T>* node) const;
	int getHeight(const Node<T>* node) const;
	void inorderWalk(Node<T>* node) const;

public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree<T>& scr) = delete;
	BinarySearchTree(BinarySearchTree<T>&& scr) noexcept;
	BinarySearchTree <T>& operator= (const BinarySearchTree <T>& src) = delete;
	BinarySearchTree <T>& operator= (BinarySearchTree <T>&& src) noexcept;
	virtual ~BinarySearchTree();
	
	bool iterativeSearch(const T& key) const;
	bool insert(const T& key);
	bool deleteKey(const T& key);
	void print(std::ostream& out) const;
	int getCount() const;
	int getHeight() const;
	void iterativeInorderWalk() const;
	void inorderWalk() const;
	void walkByLevels() const;
	bool isSimilar(const BinarySearchTree<T>& other) const;
	bool isSimilarHelper(const Node<T>* node1, const Node<T>* node2) const;
	bool isIdenticalKey(const BinarySearchTree<T>& other) const;
	void inorderTraversal(const Node<T>* node, std::vector<T>& keys) const;
};

extern template class BinarySearchTree<int>;
extern template class BinarySearchTree<float>;
extern template class BinarySearchTree<double>;