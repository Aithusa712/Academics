#include <iostream>
#include "BST.h"

using namespace std;

void processNode(int& num)
{
	cout << num << endl;
}

int main()
{
	BST<int> myNum;

	myNum.Insert(3);
	myNum.Insert(7);
	myNum.Insert(2);

	cout << "Numbers in my BST" << endl << "-----------" << endl;
	
	cout << "inOrder Traversal"<< endl << "-----------" << endl;
	myNum.inOrder(processNode);
	cout << "preOrder Traversal"<< endl << "-----------" << endl;
	myNum.preOrder(processNode);
	cout << "postOrder Traversal"<< endl << "-----------" << endl;
	myNum.postOrder(processNode);
	return 0;
}
