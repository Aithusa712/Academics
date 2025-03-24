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
class intBst
{
public:
    intBst();
    ~intBst();
    void Insert(T newData);
    void Insert(Node<T>* newNode, Node<T>* root);
    void Delete(Node<T>*& root);
    bool Search(Node<T>* node, T target);
    void inOrder(Node<T>* root);
    void preOrder(Node<T>* root);
    void postOrder(Node<T>* root);
    void printInOrder();
    void printPostOrder();
    void printPreOrder();
    void DeleteTree();
    bool SearchTree(int target);

protected:
    Node<T>* root;

};

template <typename T>
intBst<T>::intBst()
{
    root = nullptr;
}

template <typename T>
intBst<T>::~intBst()
{
    Delete(root);
}

template <typename T>
void intBst<T>::Insert(T newData)
{
    Node<T>* newNode = new Node<T>(newData);
    if (root == nullptr)
    {
        root = newNode;
        return;
    }
    else
    {
        Insert(newNode, root);
    }
}

template <typename T>
void intBst<T>::Insert(Node<T>* newNode, Node<T>* root)
{
    if (newNode->info < root->info)
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
        if (root->right == nullptr)
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
void intBst<T>::Delete(Node<T>*& root)
{
    if (root == nullptr)
    {
        return;
    }

    Delete(root->left);
    Delete(root->right);

    delete root;
    root = nullptr;
}

template <typename T>
bool intBst<T>::Search(Node<T>* node, T target)
{
    if (node == nullptr)
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
void intBst<T>::inOrder(Node<T>* root)
{
    if (root == nullptr)
    {
        return;
    }
    inOrder(root->left);
    cout << root->info << " ";
    inOrder(root->right);
}

template <typename T>
void intBst<T>::preOrder(Node<T>* root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->info << " ";
    preOrder(root->left);
    preOrder(root->right);
}

template <typename T>
void intBst<T>::postOrder(Node<T>* root)
{
    if (root == nullptr)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->info << " ";
}

template <typename T>
void intBst<T>::printInOrder()
{
    if(root == nullptr)
    {
        cout << "Tree is empty";
    }
    else
    {
        inOrder(root);
    }

}

template <typename T>
void intBst<T>::printPostOrder()
{
    if(root == nullptr)
    {
        cout << "Tree is empty";
    }
    else
    {
       postOrder(root);
    }

}

template <typename T>
void intBst<T>::printPreOrder()
{
    if(root == nullptr)
    {
        cout << "Tree is empty";
    }
    else
    {
        preOrder(root);
    }

}

template <typename T>
void intBst<T>::DeleteTree()
{
    Delete(root);
}

template <typename T>
bool intBst<T>::SearchTree(int target)
{
    if (Search(root, target))
    {
        return true;
    }
    else
    {
        return false;
    }
}

