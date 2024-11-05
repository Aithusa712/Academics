#include <iostream>
#include "BST.h"
using namespace std;

void printNode(int& num )
{
	cout<< num << ", ";
}
int main()
{
	BST<int> myNumber;
	myNumber.Insert(9);
	myNumber.Insert(2);
	myNumber.Insert(3);
	myNumber.Insert(8);
	cout << "InOrder Traversal: ";
	myNumber.inOrder(printNode);
	cout << "\nPreOrder Traversal: ";
	myNumber.preOrder(printNode);
	cout << "\nPostOrder Traversal: ";
	myNumber.postOrder(printNode);

	return 0;
}
