#include <iostream>
using namespace std;

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
	typedef void (*PN)(T&);
	BST();
	~BST();
	void Insert(Node<T>* root, Node<T>* value);
	void Insert(T value);
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
template <typename T>
void BST<T>::Insert(T value)
{
	Node<T>* newNode = new Node<T>(value);
	if(root == nullptr)
	{
		root = newNode;
	}
	else
	{
		Insert(root, newNode);
	}
}
template <typename T>
void BST<T>::Insert(Node<T>* root, Node<T>* newNode)
{
	if(newNode->info < root->info)
	{
		if(root->left==nullptr)
		{
			root->left = newNode;
		}
		else
		{
			Insert(root->left, newNode);
		}
	}
	else
		{
		if(root->right==nullptr)
		{
			root->right= newNode;
		}
		else
		{
			Insert(root->right, newNode);
		}
	}
}
template <typename T>
bool BST<T>::Search(Node<T>* node, T target)
{
	if(node==nullptr)
	{
		return false;
	}
	if(node->info == target)
	{
		return true;
	}
	if(target < node->info)
	{
		Search(node->left,target);
	}
	else
	{
		Search(node->right, target);
	}
}
template <typename T>
bool BST<T>::Search(T target)
{
	if(root==nullptr)
	{
		cout << "Tree is empty" << endl; 
	}
}
template <typename T>
void BST<T>::Delete(Node<T>* root)
{
	if(root==nullptr)
	{
		return;
	}

	delete root;
	root=nullptr;
}
template <typename T>
void BST<T>::inOrder(Node<T>* root, PN processNode)
{
	if(root==nullptr)
	{
		return;
	}
	inOrder(root->left, processNode);
	processNode(root->info);
	inOrder(root->right, processNode);
}
template <typename T>
void BST<T>::preOrder(Node<T>* root, PN processNode)
{
	if(root==nullptr)
	{
		return;
	}
	processNode(root->info);
	preOrder(root->left, processNode);
	preOrder(root->right, processNode);
}
template <typename T>
void BST<T>::postOrder(Node<T>* root, PN processNode)
{
	if(root==nullptr)
	{
		return;
	}
	postOrder(root->left, processNode);
	postOrder(root->right, processNode);
	processNode(root->info);
}
template <typename T>
void BST<T>::inOrder(PN processNode)
{
	if(root==nullptr)
	{
		cout << "Tree is empty" << endl;
	}
	else
	{
		inOrder(root, processNode);
	}
}
template <typename T>
void BST<T>::preOrder(PN processNode)
{
	if(root==nullptr)
	{
		cout << "Tree is empty" << endl;
	}
	else
	{
		preOrder(root, processNode);
	}
}
template <typename T>
void BST<T>::postOrder(PN processNode)
{	
	if(root==nullptr)
	{
		cout << "Tree is empty" << endl;
	}
	else
	{
		postOrder(root, processNode);
	}
}	

