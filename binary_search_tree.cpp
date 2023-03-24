// Включаем заголовочный файл с определением класса бинарного дерева поиска
#include "binary_search_tree.h"
#include <iostream>
#include <stack> // Для реализации итеративного обхода
#include <queue> // Для реализации обхода по уровням

// Реализация метода поиска узла с заданным ключом, возвращая указатель на узел
template <class T>
typename BinarySearchTree<T>::Node<T>* BinarySearchTree<T>::iterativeSearchNode(const T& key) const {
    Node<T>* current = root_; // Начинаем с корня дерева
    while (current != nullptr && key != current->key_) {
        if (key < current->key_)
            current = current->left_; // Если ключ меньше, идем влево
        else
            current = current->right_; // Если ключ больше, идем вправо
    }
    return current; // Возвращаем найденный узел или nullptr, если ключ не найден
}

// Рекурсивная функция печати узлов дерева (in-order)
template<class T>
void BinarySearchTree<T>::printNode(std::ostream& out, Node<T>* node, std::string indent, bool isLast) const
{
    if (node == nullptr)
    {
        return;
    }

    out << indent;

    if (isLast)
    {
        out << "\\";
        indent += "  ";
    }
    else
    {
        out << "/";
        indent += "| ";
    }

    out << "--" << node->key_ << "--" << std::endl;

    if (node->left_ != nullptr || node->right_ != nullptr)
    {
        printNode(out, node->left_, indent, false);
        printNode(out, node->right_, indent, true);
    }
}

template<class T>
void BinarySearchTree<T>::print(std::ostream& out) const
{
    printNode(out, root_, "", true);
}


// Рекурсивная функция подсчета узлов в дереве
template<class T>
int BinarySearchTree<T>::getCount(const Node<T>* node) const
{
    if (node == nullptr) {
        return 0;
    }
    // Возвращаем 1 (текущий узел) + количество узлов в левом и правом поддереве
    return 1 + getCount(node->left_) + getCount(node->right_);
}

// Рекурсивная функция вычисления высоты дерева
template<class T>
int BinarySearchTree<T>::getHeight(const Node<T>* node) const
{
    if (node == nullptr) {
        return -1;
    }
    // Возвращаем 1 + максимальную высоту между левым и правым поддеревьями
    return 1 + std::max(getHeight(node->left_), getHeight(node->right_));
}

// Рекурсивная функция in-order обхода дерева
template<class T>
void BinarySearchTree<T>::inorderWalk(Node<T>* node) const
{
    if (node != nullptr) {
        inorderWalk(node->left_); // Обходим левое поддерево
        std::cout << node->key_ << " "; // Печатаем ключ текущего узла
        inorderWalk(node->right_); // Обходим правое поддерево
    }
}

// Конструктор по умолчанию
template <class T>
BinarySearchTree<T>::BinarySearchTree() : root_(nullptr) { }

// Конструктор перемещения
template <class T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T>&& src) noexcept : root_(src.root_) {
    src.root_ = nullptr; // Устанавливаем корень исходного дерева в nullptr, чтобы избежать удаления узлов
}

// Оператор перемещения
template <class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(BinarySearchTree<T>&& src) noexcept {
    if (this != &src) {
        delete root_; // Удаляем текущее дерево
        root_ = src.root_; // Перемещаем корень исходного дерева
        src.root_ = nullptr; // Устанавливаем корень исходного дерева в nullptr, чтобы избежать удаления узлов
    }
    return *this; // Возвращаем ссылку на текущий объект
}

// Деструктор
template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{
    delete root_; // Удаляем корень и все связанные узлы дерева
}

// Функция проверки наличия ключа в дереве
template<class T>
bool BinarySearchTree<T>::iterativeSearch(const T& key) const
{
    return iterativeSearchNode(key) != nullptr; // Возвращаем true, если узел найден, иначе false
}

// Функция вставки ключа в дерево
template<class T>
bool BinarySearchTree<T>::insert(const T& key)
{
    Node<T>* newNode = new Node<T>(key); // Создаем новый узел с заданным ключом
    if (root_ == nullptr) {
        root_ = newNode; // Если дерево пустое, устанавливаем новый узел в качестве корня
        return true;
    }

    Node<T>* current = root_;
    Node<T>* parent = nullptr;

    // Ищем место для вставки нового узла
    while (current != nullptr) {
        parent = current;
        if (key < current->key_)
            current = current->left_; // Если ключ меньше, идем влево
        else if (key > current->key_)
            current = current->right_; // Если ключ больше, идем вправо
        else
            return false; // Если ключ уже существует, возвращаем false
    }

    newNode->p_ = parent; // Устанавливаем родителя для нового узла
    if (key < parent->key_)
        parent->left_ = newNode; // Если ключ меньше, устанавливаем новый узел слева от родителя
    else
        parent->right_ = newNode; // Если ключ больше, устанавливаем новый узел справа от родителя

    return true;
}

// Функция удаления ключа из дерева
template<class T>
bool BinarySearchTree<T>::deleteKey(const T& key)
{
    Node<T>* nodeToDelete = iterativeSearchNode(key); // Находим узел с заданным ключом
    if (nodeToDelete == nullptr) {
        return false; // Если ключ не найден, возвращаем false
    }

    Node<T>* nodeToRemove = nullptr;
    // Если у узла есть только один потомок или нет потомков, удаляем сам узел
    if (nodeToDelete->left_ == nullptr || nodeToDelete->right_ == nullptr) {
        nodeToRemove = nodeToDelete;
    }
    else {
        // Если у узла два потомка, ищем его преемника (следующий узел в in-order обходе)
        nodeToRemove = nodeToDelete->right_;
        while (nodeToRemove->left_ != nullptr) {
            nodeToRemove = nodeToRemove->left_;
        }
    }

    Node<T>* childNode = nullptr;
    if (nodeToRemove->left_ != nullptr) {
        childNode = nodeToRemove->left_; // Если есть левый потомок, выбираем его
    }
    else {
        childNode = nodeToRemove->right_; // Иначе выбираем правого потомка или nullptr, если нет потомков
    }

    // Обновляем родителя потомка
    if (childNode != nullptr) {
        childNode->p_ = nodeToRemove->p_;
    }

    // Если удаляемый узел является корнем, обновляем корень дерева
    if (nodeToRemove->p_ == nullptr) {
        root_ = childNode;
    }
    else if (nodeToRemove == nodeToRemove->p_->left_) { // Если удаляемый узел является левым потомком
        nodeToRemove->p_->left_ = childNode;
    }
    else { // Если удаляемый узел является правым потомком
        nodeToRemove->p_->right_ = childNode;
    }

    // Если удаляемый узел не совпадает с узлом, содержащим ключ, обновляем ключ
    if (nodeToRemove != nodeToDelete) {
        nodeToDelete->key_ = nodeToRemove->key_;
    }

    delete nodeToRemove; // Удаляем узел
    return true;
}

// Функция подсчета узлов в дереве
template<class T>
int BinarySearchTree<T>::getCount() const
{
    return getCount(root_);
}

// Функция вычисления высоты дерева
template<class T>
int BinarySearchTree<T>::getHeight() const
{
    return getHeight(root_);
}

// Функция итеративного in-order обхода дерева
template<class T>
void BinarySearchTree<T>::iterativeInorderWalk() const
{
    Node<T>* current = root_;
    std::stack<Node<T>*> stack; // Создаем стек для итеративного обхода

    // Пока стек не пуст или текущий узел не равен nullptr
    while (!stack.empty() || current != nullptr) {
        if (current != nullptr) {
            stack.push(current); // Добавляем текущий узел в стек
            current = current->left_; // Переходим к левому потомку
        }
        else {
            current = stack.top(); // Получаем следующий узел из стека
            stack.pop(); // Удаляем узел из стека
            std::cout << current->key_ << " "; // Выводим ключ текущего узла
            current = current->right_; // Переходим к правому потомку
        }
    }

    std::cout << std::endl; // Выводим перенос строки после обхода
}

// Функция in-order обхода дерева
template<class T>
void BinarySearchTree<T>::inorderWalk() const
{
    inorderWalk(root_); // Вызываем рекурсивную функцию с корнем дерева
    std::cout << std::endl; // Выводим перенос строки после обхода
}

// Функция обхода дерева по уровням (ширина в первую очередь)
template<class T>
void BinarySearchTree<T>::walkByLevels() const
{
    if (root_ == nullptr) {
        return; // Если дерево пустое, выходим из функции
    }

    std::queue<Node<T>*> queue; // Создаем очередь для обхода по уровням
    queue.push(root_); // Добавляем корень дерева в очередь

    // Пока очередь не пуста
    while (!queue.empty()) {
        Node<T>* current = queue.front(); // Получаем первый узел из очереди
        queue.pop(); // Удаляем узел из очереди

        std::cout << current->key_ << " "; // Выводим ключ текущего узла

        // Если у текущего узла есть левый потомок, добавляем его в очередь
        if (current->left_ != nullptr) {
            queue.push(current->left_);
        }
        // Если у текущего узла есть правый потомок, добавляем его в очередь
        if (current->right_ != nullptr) {
            queue.push(current->right_);
        }
    }

    std::cout << std::endl; // Выводим перенос строки после обхода
}

// Функция проверки сходства двух деревьев по структуре (ключи игнорируются)
template<class T>
bool BinarySearchTree<T>::isSimilar(const BinarySearchTree<T>& other) const
{
    return isSimilarHelper(root_, other.root_);
}

// Вспомогательная рекурсивная функция для проверки сходства двух узлов и их потомков
template<class T>
bool BinarySearchTree<T>::isSimilarHelper(const Node<T>* node1, const Node<T>* node2) const
{
    if (node1 == nullptr && node2 == nullptr) {
        return true; // Если оба узла пусты, они сходны
    }

    if (node1 == nullptr || node2 == nullptr) {
        return false; // Если один из узлов пуст, а другой нет, они не сходны
    }

    // Рекурсивно проверяем сходство левых и правых потомков
    return isSimilarHelper(node1->left_, node2->left_) &&
        isSimilarHelper(node1->right_, node2->right_);
}

// Функция проверки идентичности ключей двух деревьев (структура игнорируется)
template<class T>
bool BinarySearchTree<T>::isIdenticalKey(const BinarySearchTree<T>& other) const
{
    std::vector<T> thisInorderKeys; // Вектор для хранения ключей данного дерева
    std::vector<T> otherInorderKeys; // Вектор для хранения ключей другого дерева
    inorderTraversal(root_, thisInorderKeys); // Выполняем in-order обход и сохраняем ключи данного дерева
    inorderTraversal(other.root_, otherInorderKeys); // Выполняем in-order обход и сохраняем ключи другого дерева

    return thisInorderKeys == otherInorderKeys; // Возвращаем true, если векторы ключей идентичны
}

// Вспомогательная функция для in-order обхода дерева и сохранения ключей в векторе
template<class T>
void BinarySearchTree<T>::inorderTraversal(const Node<T>* node, std::vector<T>& keys) const
{
    if (node != nullptr) {
        inorderTraversal(node->left_, keys); // Рекурсивно обходим левое поддерево
        keys.push_back(node->key_); // Сохраняем ключ текущего узла в векторе
        inorderTraversal(node->right_, keys); // Рекурсивно обходим правое поддерево
    }
}

template class BinarySearchTree<int>;
template class BinarySearchTree<float>;
template class BinarySearchTree<double>;



