#include <iostream>
using namespace std;
// BST.h
template <typename T>
struct Node
{
	T info;
	Node* left;
	Node* right;
	Node(T newInfo)
	{
		info = newInfo;
		left = nullptr;
		right = nullptr;
	}
};

template <typename T>
class BST
{
public:
	BST();
	~BST();
	typedef void (*PN)(T&);
	void Insert(T newData);
	void Insert(Node<T>* node, Node<T>* root);
	bool Search(Node<T>* node, T target);
	bool Search(T target);
	void Delete(Node<T>* root);
	void inOrder(Node<T>* root, PN processNode);
	void preOrder(Node<T>* root, PN processNode);
	void postOrder(Node<T>* root, PN processNode);
	void inOrder(PN processNode);
	void preOrder(PN processNode);
	void postOrder(PN processNode);
	
private:

Node<T>* root;
	
};

// implementation

// constructors/deconstructors

template <typename T>
BST<T>::BST()
{
	root = nullptr;
}

template <typename T>
BST<T>::~BST()
{
	Delete(root);
}

// insert/delete/search

template <typename T>
void BST<T>::Insert(T newData)
{
	Node<T>* newNode = new Node<T>(newData);
	if(root == nullptr)
	{
		root = newNode;
	}
	else
	{
		Insert(newNode, root);
	}

}

template <typename T>
void BST<T>::Insert(Node<T>* newNode, Node<T>* root)
{
	if(newNode->info < root->info)
	{
		if (root->left == nullptr)
		{
			root->left = newNode;
		}
		else
		{
			Insert(newNode, root->left);
		}
	}
	else
	{
		if(root->right == nullptr)
		{
			root->right = newNode;
		}
		else
		{
			Insert(newNode, root->right);
		}
	}
}

template <typename T>
void BST<T>::Delete(Node<T>* root)
{
	if(root==nullptr)
	{
		return;
	}
	
	Delete(root->left);
	Delete(root->right);

	delete root;
	root = nullptr;
}

template <typename T>
bool BST<T>::Search(Node<T>* node, T target)
{
	if (node==nullptr)
	{
	return false;
	}
	if (node->info == target)
	{
	return true;
	}
	if (target < node->info)
	{
		return Search(node->left, target);
	}
	else
	{
		return Search(node->right, target);
	}
}
template <typename T>
bool BST<T>::Search(T target)
{
	if (Search(root,target))
	{
		return true;
	}
	else 
	{
		return false;
	}
}



// Traversal

template <typename T>
void BST<T>::inOrder(Node<T>* root, PN processNode)
{
	if(root == nullptr)
	{
		return;
	}

	else
	{
	inOrder(root->left, processNode);
	processNode(root->info);
	inOrder(root->right, processNode);
	}


}

template <typename T>
void BST<T>::preOrder(Node<T>* root, PN processNode)
{
	if(root == nullptr)
	{
		return;
	}

	else
	{
	processNode(root->info);
	preOrder(root->left,processNode);
	preOrder(root->right,processNode);
	}


}

template <typename T>
void BST<T>::postOrder(Node<T>* root, PN processNode)
{
	if(root == nullptr)
	{
		return;
	}

	else
	{
	postOrder(root->left,processNode);
	postOrder(root->right,processNode);
	processNode(root->info);
	}


}


// we will need a function to call the root within the class

template <typename T>
void BST<T>::inOrder(PN processNode)
{
	if(root == nullptr)
	{
		cout<<"Tree is empty"<< endl;
	}
	else
	{
		inOrder(root, processNode);
	}
}

template <typename T>
void BST<T>::preOrder(PN processNode)
{
	if(root == nullptr)
	{
		cout<<"Tree is empty"<< endl;
	}
	else
	{
		preOrder(root, processNode);
	}
}

template <typename T>
void BST<T>::postOrder(PN processNode)
{
	if(root == nullptr)
	{
		cout<<"Tree is empty"<< endl;
	}
	else
	{
		postOrder(root, processNode);
	}
}
