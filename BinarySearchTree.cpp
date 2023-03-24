#include "binary_search_tree.h"
#include <iostream>
#include <vector>

void testInsertAndPrint();
void testDeleteKey();
void testIterativeSearch();
void testIterativeInorderWalk();
void testInorderWalk();
void testWalkByLevels();
void testIsSimilar();
void testIsIdenticalKey();

int main() {
    std::cout << "Test insert and print:" << std::endl;
    testInsertAndPrint();
    std::cout << std::endl;

    std::cout << "Test delete key:" << std::endl;
    testDeleteKey();
    std::cout << std::endl;

    std::cout << "Test iterative search:" << std::endl;
    testIterativeSearch();
    std::cout << std::endl;

    std::cout << "Test inorder walk:" << std::endl;
    testInorderWalk();
    std::cout << std::endl;

    std::cout << "Test iterative inorder walk:" << std::endl;
    testIterativeInorderWalk();
    std::cout << std::endl;

    std::cout << "Test walk by levels:" << std::endl;
    testWalkByLevels();
    std::cout << std::endl;

    std::cout << "Test is similar:" << std::endl;
    testIsSimilar();
    std::cout << std::endl;

    std::cout << "Test is identical key:" << std::endl;
    testIsIdenticalKey();
    std::cout << std::endl;

    return 0;
}

// Функция для тестирования операции вставки и вывода элементов дерева
void testInsertAndPrint() {
    BinarySearchTree<int> bst; // Создание объекта двоичного дерева поиска

    // Вектор ключей для вставки в дерево
    std::vector<int> keys = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };

    // Вставка ключей в дерево
    for (int key : keys) {
        bst.insert(key);
    }

    // Вывод элементов дерева
    bst.print(std::cout);
}

// Функция для тестирования удаления элемента из дерева
void testDeleteKey() {
    BinarySearchTree<int> bst; // Создание объекта двоичного дерева поиска

    // Вектор ключей для вставки в дерево
    std::vector<int> keys = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };

    // Вставка ключей в дерево
    for (int key : keys) {
        bst.insert(key);
    }

    // Удаление элемента с ключом 10 из дерева
    bst.deleteKey(10);

    // Вывод элементов дерева
    bst.print(std::cout);
}

// Функция для тестирования итеративного поиска элемента в дереве
void testIterativeSearch() {
    BinarySearchTree<int> bst; // Создание объекта двоичного дерева поиска

    // Вектор ключей для вставки в дерево
    std::vector<int> keys = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };

    // Вставка ключей в дерево
    for (int key : keys) {
        bst.insert(key);
    }

    // Поиск элемента с ключом 10 и вывод результата
    std::cout << "Searching for 10: " << (bst.iterativeSearch(10) ? "Found" : "Not found") << std::endl;

    // Поиск элемента с ключом 20 и вывод результата
    std::cout << "Searching for 20: " << (bst.iterativeSearch(20) ? "Found" : "Not found") << std::endl;
}

// Функция для тестирования обхода дерева in-order
void testInorderWalk() {
    BinarySearchTree<int> bst; // Создание объекта двоичного дерева поиска

    // Вектор ключей для вставки в дерево
    std::vector<int> keys = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };

    // Вставка ключей в дерево
    for (int key : keys) {
        bst.insert(key);
    }

    // Обход дерева in-order и вывод элементов
    bst.inorderWalk();
}

// Функция для тестирования сравнения двух деревьев на структурное сходство
void testIsSimilar() {
    BinarySearchTree<int> bst1, bst2, bst3, bst4;

    // Векторы ключей для вставки в деревья
    std::vector<int> keys1 = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };
    std::vector<int> keys2 = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };
    std::vector<int> keys3 = { 8, 3, 10, 1, 6, 14, 4, 7 };
    std::vector<int> keys4 = { 10, 5, 15, 2, 7, 12, 17, 1, 6, 8, 11, 14, 16, 18 };

    // Вставка ключей в деревья
    for (int key : keys1) {
        bst1.insert(key);
    }

    for (int key : keys2) {
        bst2.insert(key);
    }

    for (int key : keys3) {
        bst3.insert(key);
    }

    for (int key : keys4) {
        bst4.insert(key);
    }

    // Сравнение деревьев на структурное сходство и вывод результатов
    std::cout << "Is bst1 similar to bst2: " << (bst1.isSimilar(bst2) ? "Yes" : "No") << std::endl;
    std::cout << "Is bst1 similar to bst3: " << (bst1.isSimilar(bst3) ? "Yes" : "No") << std::endl;
    std::cout << "Is bst1 similar to bst4: " << (bst1.isSimilar(bst4) ? "Yes" : "No") << std::endl;
}

// Функция для тестирования итеративного обхода дерева in-order
void testIterativeInorderWalk() {
    BinarySearchTree<int> bst; // Создание объекта двоичного дерева поиска

    // Вектор ключей для вставки в дерево
    std::vector<int> keys = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };

    // Вставка ключей в дерево
    for (int key : keys) {
        bst.insert(key);
    }

    // Итеративный обход дерева in-order и вывод элементов
    bst.iterativeInorderWalk();
}

// Функция для тестирования обхода дерева по уровням
void testWalkByLevels() {
    BinarySearchTree<int> bst; // Создание объекта двоичного дерева поиска

    // Вектор ключей для вставки в дерево
    std::vector<int> keys = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };

    // Вставка ключей в дерево
    for (int key : keys) {
        bst.insert(key);
    }

    // Обход дерева по уровням и вывод элементов
    bst.walkByLevels();
}

// Функция для тестирования сравнения двух деревьев на идентичность по ключам
void testIsIdenticalKey() {
    BinarySearchTree<int> bst1, bst2, bst3;

    // Векторы ключей для вставки в деревья
    std::vector<int> keys1 = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };
    std::vector<int> keys2 = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };
    std::vector<int> keys3 = { 8, 3, 10, 1, 6, 14, 4, 7 };

    // Вставка ключей в деревья
    for (int key : keys1) {
        bst1.insert(key);
    }

    for (int key : keys2) {
        bst2.insert(key);
    }

    for (int key : keys3) {
        bst3.insert(key);
    }

    // Сравнение деревьев на идентичность по ключам и вывод результатов
    std::cout << "Is bst1 identical to bst2: " << (bst1.isIdenticalKey(bst2) ? "Yes" : "No") << std::endl;
    std::cout << "Is bst1 identical to bst3: " << (bst1.isIdenticalKey(bst3) ? "Yes" : "No") << std::endl;
}