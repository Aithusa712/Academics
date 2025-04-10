#include <iostream>

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
    typedef void (*PN)(T&);

    intBst();
    ~intBst();
    void Insert(T newData);
    void Delete(Node<T>*& root);
    bool Search(Node<T>* node, T target)const;
    void inOrder(Node<T>* root, PN processNode)const;
    void preOrder(Node<T>* root, PN processNode)const;
    void postOrder(Node<T>* root, PN processNode)const;
    void printInOrder(PN processNode);
    void printPostOrder(PN processNode);
    void printPreOrder(PN processNode);
    void DeleteTree();
    bool SearchTree(const T& target);

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
    Node<T>* current;
    Node<T>* trailCurrent;
    if (root == nullptr)
    {
        root = newNode;
        return;
    }
    else
    {
        current = root;
    }
    while(current != nullptr)
    {
        trailCurrent = current;
        if (current->info == newData)
        {
            return;
        }
        else if (current->info > newData)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    if(trailCurrent->info>newData)
    {
        trailCurrent->left = newNode;
    }
    else
    {
        trailCurrent->right = newNode;
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
bool intBst<T>::Search(Node<T>* node, T target) const
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
void intBst<T>::inOrder(Node<T>* root, PN processNode) const
{
    if (root == nullptr)
    {
        return;
    }
    inOrder(root->left, processNode);
    processNode(root->info);
    inOrder(root->right, processNode);
}

template <typename T>
void intBst<T>::preOrder(Node<T>* root, PN processNode) const
{
    if (root == nullptr)
    {
        return;
    }
    processNode(root->info);
    preOrder(root->left, processNode);
    preOrder(root->right, processNode);
}

template <typename T>
void intBst<T>::postOrder(Node<T>* root, PN processNode) const
{
    if (root == nullptr)
    {
        return;
    }
    postOrder(root->left, processNode);
    postOrder(root->right, processNode);
    processNode(root->info);
}

template <typename T>
void intBst<T>::printInOrder(PN processNode)
{
    if(root == nullptr)
    {
        std::cout << "Tree is empty";
    }
    else
    {
        inOrder(root, processNode);
    }
}

template <typename T>
void intBst<T>::printPostOrder(PN processNode)
{
    if(root == nullptr)
    {
        std::cout << "Tree is empty";
    }
    else
    {
       postOrder(root, processNode);
    }
}

template <typename T>
void intBst<T>::printPreOrder(PN processNode)
{
    if(root == nullptr)
    {
        std::cout << "Tree is empty";
    }
    else
    {
        preOrder(root, processNode);
    }
}

template <typename T>
void intBst<T>::DeleteTree()
{
    Delete(root);
}

template <typename T>
bool intBst<T>::SearchTree(const T& target)
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



