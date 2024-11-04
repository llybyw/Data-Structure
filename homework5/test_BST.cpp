#include <iostream>
#include "BST.h"  // 假设 BinarySearchTree 类定义在这个头文件中
void testBinarySearchTree() {
    BinarySearchTree<int> bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    std::cout << "Initial Tree:" << std::endl;
    bst.printTree();
    bst.remove(3);
    std::cout << "Tree after removing 3:" << std::endl;
    bst.printTree();
    bst.makeEmpty();
    std::cout << "Tree after making empty:" << std::endl;
    bst.printTree();
 
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);
    std::cout << "Initial Tree:" << std::endl;
    bst.printTree();
    bst.remove(5);
    std::cout << "Tree after removing 5:" << std::endl;
    bst.printTree();
    bst.makeEmpty();
    std::cout << "Tree after making empty:" << std::endl;
    bst.printTree();

    bst.insert(21);
    bst.insert(15);
    bst.insert(35);
    bst.insert(9);
    bst.insert(28);
    bst.insert(37);   
    std::cout << "Initial Tree:" << std::endl;
    bst.printTree();
    bst.remove(15);
    std::cout << "Tree after removing 15:" << std::endl;
    bst.printTree();
    bst.makeEmpty();
    std::cout << "Tree after making empty:" << std::endl;
    bst.printTree();

    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);
    std::cout << "Initial Tree:" << std::endl;
    bst.printTree();
    bst.remove(10);
    std::cout << "Tree after removing 10:" << std::endl;
    bst.printTree();
    bst.makeEmpty();
    std::cout << "Tree after making empty:" << std::endl;
    bst.printTree();
}

int main() {
    testBinarySearchTree();
    return 0;
}