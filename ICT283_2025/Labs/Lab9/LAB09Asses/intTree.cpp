#include <iostream>
#include "Bst.h"

using namespace std;

void printNode(int& node)
{
    cout << node << ",";
}
int main()
{
    Bst<int> bstTest;
    bstTest.Insert(29);
    bstTest.Insert(32);
    bstTest.Insert(14);
    bstTest.Insert(61);
    bstTest.Insert(12);
    bstTest.Insert(65);
    bstTest.Insert(41);
    bstTest.Insert(84);

    cout << "---------Traversal---------";
    cout << endl;
    cout << "inOrder Traversal: ";
    bstTest.printInOrder(printNode);
    cout << endl;
    cout << "preOrder Traversal: ";
    bstTest.printPreOrder(printNode);
    cout << endl;
    cout << "postOrder Traversal: ";
    bstTest.printPostOrder(printNode);

    cout << endl;
    cout << "---------Search Tree---------";
    cout << endl;
    cout << "Search Test (target is 29): ";
    cout << bstTest.SearchTree(29);
    cout << endl;
    cout << "Search Test (target is 10): ";
    cout << bstTest.SearchTree(10);
    cout << endl;

    cout << "---------Deleting Tree---------";
    cout << endl;

    bstTest.DeleteTree();
    cout << "inOrder Traversal: ";
    bstTest.printInOrder(printNode);
    cout << endl;
    cout << "preOrder Traversal: ";
    bstTest.printPreOrder(printNode);
    cout << endl;
    cout << "postOrder Traversal: ";
    bstTest.printPostOrder(printNode);
    cout << endl;

    return 0;
}
