#include "binary_search_tree.h"
#include <iostream>
#include <stack>
#include <queue>
#include <string>

template <class T>
typename BinarySearchTree<T>::Node<T>* BinarySearchTree<T>::iterativeSearchNode(const T& key) const {
    Node<T>* current = root_;
    while (current != nullptr && key != current->key_) {
        if (key < current->key_)
            current = current->left_;
        else
            current = current->right_;
    }
    return current;
}

template<class T>
void BinarySearchTree<T>::printNode(std::ostream& out, Node<T>* root) const {
    if (root != nullptr) {
        out << '(';
        printNode(out, root->left_);
        out << root->key_;
        printNode(out, root->right_);
        out << ')';
    }
}

template <class T>
void BinarySearchTree<T>::print(std::ostream& out) const {
    printNode(out, root_);
}

template<class T>
int BinarySearchTree<T>::getCount(const Node<T>* node) const
{
    if (node == nullptr) {
        return 0;
    }
    return 1 + getCount(node->left_) + getCount(node->right_);
}

template<class T>
int BinarySearchTree<T>::getHeight(const Node<T>* node) const
{
    if (node == nullptr) {
        return -1;
    }
    return 1 + std::max(getHeight(node->left_), getHeight(node->right_));
}

template<class T>
void BinarySearchTree<T>::inorderWalk(Node<T>* node) const
{
    if (node != nullptr) {
        inorderWalk(node->left_);
        std::cout << node->key_ << " ";
        inorderWalk(node->right_);
    }
}

template <class T>
BinarySearchTree<T>::BinarySearchTree() : root_(nullptr) { }

template <class T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T>&& src) noexcept : root_(src.root_) {
    src.root_ = nullptr;
}

template <class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(BinarySearchTree<T>&& src) noexcept {
    if (this != &src) {
        delete root_;
        root_ = src.root_;
        src.root_ = nullptr;
    }
    return *this;
}

template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{
    delete root_;
}

template<class T>
bool BinarySearchTree<T>::iterativeSearch(const T& key) const
{
    return iterativeSearchNode(key) != nullptr;
}

template<class T>
bool BinarySearchTree<T>::insert(const T& key)
{
    Node<T>* newNode = new Node<T>(key);
    if (root_ == nullptr) {
        root_ = newNode;
        return true;
    }

    Node<T>* current = root_;
    Node<T>* parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (key < current->key_)
            current = current->left_;
        else if (key > current->key_)
            current = current->right_;
        else
            return false; // Key already exists.
    }

    newNode->p_ = parent;
    if (key < parent->key_)
        parent->left_ = newNode;
    else
        parent->right_ = newNode;

    return true;
}

template<class T>
bool BinarySearchTree<T>::deleteKey(const T& key)
{
    Node<T>* nodeToDelete = iterativeSearchNode(key);
    if (nodeToDelete == nullptr) {
        return false; // Key not found.
    }

    Node<T>* nodeToRemove = nullptr;
    if (nodeToDelete->left_ == nullptr || nodeToDelete->right_ == nullptr) {
        nodeToRemove = nodeToDelete;
    }
    else {
        // Find the successor of the node to delete
        nodeToRemove = nodeToDelete->right_;
        while (nodeToRemove->left_ != nullptr) {
            nodeToRemove = nodeToRemove->left_;
        }
    }

    Node<T>* childNode = nullptr;
    if (nodeToRemove->left_ != nullptr) {
        childNode = nodeToRemove->left_;
    }
    else {
        childNode = nodeToRemove->right_;
    }

    if (childNode != nullptr) {
        childNode->p_ = nodeToRemove->p_;
    }

    if (nodeToRemove->p_ == nullptr) {
        root_ = childNode;
    }
    else if (nodeToRemove == nodeToRemove->p_->left_) {
        nodeToRemove->p_->left_ = childNode;
    }
    else {
        nodeToRemove->p_->right_ = childNode;
    }

    if (nodeToRemove != nodeToDelete) {
        nodeToDelete->key_ = nodeToRemove->key_;
    }

    delete nodeToRemove;
    return true;
}

template<class T>
int BinarySearchTree<T>::getCount() const
{
    return getCount(root_);
}

template<class T>
int BinarySearchTree<T>::getHeight() const
{
    return getHeight(root_);
}

template<class T>
void BinarySearchTree<T>::iterativeInorderWalk() const
{
    Node<T>* current = root_;
    std::stack<Node<T>*> stack;

    while (!stack.empty() || current != nullptr) {
        if (current != nullptr) {
            stack.push(current);
            current = current->left_;
        }
        else {
            current = stack.top();
            stack.pop();
            std::cout << current->key_ << " ";
            current = current->right_;
        }
    }

    std::cout << std::endl;
}

template<class T>
void BinarySearchTree<T>::inorderWalk() const
{
    inorderWalk(root_);
    std::cout << std::endl;
}

template<class T>
void BinarySearchTree<T>::walkByLevels() const
{
    if (root_ == nullptr) {
        return;
    }

    std::queue<Node<T>*> queue;
    queue.push(root_);

    while (!queue.empty()) {
        Node<T>* current = queue.front();
        queue.pop();

        std::cout << current->key_ << " ";

        if (current->left_ != nullptr) {
            queue.push(current->left_);
        }
        if (current->right_ != nullptr) {
            queue.push(current->right_);
        }
    }

    std::cout << std::endl;
}

template<class T>
bool BinarySearchTree<T>::isSimilar(const BinarySearchTree<T>& other) const
{
    return isSimilarHelper(root_, other.root_);
}

template<class T>
bool BinarySearchTree<T>::isSimilarHelper(const Node<T>* node1, const Node<T>* node2) const
{
    if (node1 == nullptr && node2 == nullptr) {
        return true;
    }

    if (node1 == nullptr || node2 == nullptr) {
        return false;
    }

    return isSimilarHelper(node1->left_, node2->left_) &&
        isSimilarHelper(node1->right_, node2->right_);
}

template<class T>
bool BinarySearchTree<T>::isIdenticalKey(const BinarySearchTree<T>& other) const
{
    std::vector<T> thisInorderKeys;
    std::vector<T> otherInorderKeys;
    inorderTraversal(root_, thisInorderKeys);
    inorderTraversal(other.root_, otherInorderKeys);

    return thisInorderKeys == otherInorderKeys;
}

template<class T>
void BinarySearchTree<T>::inorderTraversal(const Node<T>* node, std::vector<T>& keys) const
{
    if (node != nullptr) {
        inorderTraversal(node->left_, keys);
        keys.push_back(node->key_);
        inorderTraversal(node->right_, keys);
    }
}

template class BinarySearchTree<int>;
template class BinarySearchTree<float>;
template class BinarySearchTree<double>;