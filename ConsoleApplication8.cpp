#include "binary_search_tree.h"
#include <iostream>
#include <vector>

void testInsertAndPrint() {
    BinarySearchTree<int> bst;

    std::vector<int> keys = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };

    for (int key : keys) {
        bst.insert(key);
    }

    bst.print(std::cout);
}

void testDeleteKey() {
    BinarySearchTree<int> bst;

    std::vector<int> keys = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };

    for (int key : keys) {
        bst.insert(key);
    }

    bst.deleteKey(10);
    bst.print(std::cout);
}

void testIterativeSearch() {
    BinarySearchTree<int> bst;

    std::vector<int> keys = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };

    for (int key : keys) {
        bst.insert(key);
    }

    std::cout << "Searching for 10: " << (bst.iterativeSearch(10) ? "Found" : "Not found") << std::endl;
    std::cout << "Searching for 20: " << (bst.iterativeSearch(20) ? "Found" : "Not found") << std::endl;
}

void testInorderWalk() {
    BinarySearchTree<int> bst;

    std::vector<int> keys = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };

    for (int key : keys) {
        bst.insert(key);
    }

    bst.inorderWalk();
}

void testIterativeInorderWalk() {
    BinarySearchTree<int> bst;

    std::vector<int> keys = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };

    for (int key : keys) {
        bst.insert(key);
    }

    bst.iterativeInorderWalk();
}

void testWalkByLevels() {
    BinarySearchTree<int> bst;

    std::vector<int> keys = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };

    for (int key : keys) {
        bst.insert(key);
    }

    bst.walkByLevels();
}

void testIsSimilar() {
    BinarySearchTree<int> bst1, bst2, bst3, bst4;

    std::vector<int> keys1 = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };
    std::vector<int> keys2 = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };
    std::vector<int> keys3 = { 8, 3, 10, 1, 6, 14, 4, 7 };
    std::vector<int> keys4 = { 10, 5, 15, 2, 7, 12, 17, 1, 6, 8, 11, 14, 16, 18 };

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

    std::cout << "Is bst1 similar to bst2: " << (bst1.isSimilar(bst2) ? "Yes" : "No") << std::endl;
    std::cout << "Is bst1 similar to bst3: " << (bst1.isSimilar(bst3) ? "Yes" : "No") << std::endl;
    std::cout << "Is bst1 similar to bst4: " << (bst1.isSimilar(bst4) ? "Yes" : "No") << std::endl;
}

void testIsIdenticalKey() {
    BinarySearchTree<int> bst1, bst2, bst3;

    std::vector<int> keys1 = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };
    std::vector<int> keys2 = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };
    std::vector<int> keys3 = { 8, 3, 10, 1, 6, 14, 4, 7 };

    for (int key : keys1) {
        bst1.insert(key);
    }

    for (int key : keys2) {
        bst2.insert(key);
    }

    for (int key : keys3) {
        bst3.insert(key);
    }

    std::cout << "Is bst1 identical to bst2: " << (bst1.isIdenticalKey(bst2) ? "Yes" : "No") << std::endl;
    std::cout << "Is bst1 identical to bst3: " << (bst1.isIdenticalKey(bst3) ? "Yes" : "No") << std::endl;
}

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