#ifndef BST_H
#define BST_H
#include <iostream>
/**
 * \file Bst.h
 * \brief Header file for the BST class template
 */

/**
 * \struct Node
 * \brief Node contains the Node for the BST
 */

template <typename T> struct Node {
  T info;
  Node *left;
  Node *right;
  int bfactor;
  Node(T newInfo) {
    info = newInfo;
    left = nullptr;
    right = nullptr;
    bfactor = 1;
  }
};

/**
 * \class Bst
 * \brief Binary Search Tree.
 */
template <typename T> class Bst {
public:
  typedef void (*PN)(T &);
  /**
   * @brief  Default Constructor
   */
  Bst();
  /**
   * @brief  Deconstructor
   */
  ~Bst();
  /**
   * @brief  Inserts data into the BST
   * @brief newData - the data to be inserted
   */
  void Insert(T newData);
  /**
   * @brief Deletes the entire tree
   * @param Root the root of the BST
   */
  void Delete(Node<T> *&root);
  /**
   * @brief  Searches the tree
   * @param node the node being searched
   * @param target the target parameter to retrieve
   *
   */
  bool Search(Node<T> *node, T target) const;
  /**
   * @brief  Travels the tree in an inOrder traversal and takes in a function
   * pointer to call a function to process the node
   * @param root the root to process
   * @param processNode a function pointer to process each node
   */
  void inOrder(Node<T> *root, PN processNode) const;
  /**
   * @brief  Travels the tree in an preOrder traversal and takes in a function
   * pointer to call a function to process the node
   * @param root the root to process
   * @param processNode a function pointer to process each node
   */

  void printInOrder(PN processNode) const;
  /**
   * @brief  Allows other classes to call postOrder function
   * @param processNode a function pointer to process each node
   */

  void DeleteTree();
  /**
   * @brief  Allows other classes to call Search function
   * @param target the data that is being searched for
   */
  bool SearchTree(const T &target) const;
  /**
   * @brief Get a reference to the node with the target value
   * @param target the data to search for
   * @return Reference to the data if found, otherwise throws an exception
   */
  T &Get(T target) const;

  /**
   * @brief Helper function to find a node with the target value
   * @param node the current node being examined
   * @param target the data to search for
   * @return Pointer to the node if found, otherwise nullptr
   */
  Node<T> *FindNode(Node<T> *node, T target) const;

protected:
  Node<T> *root; /// holds the root node of the tree
  void rotateToLeft(Node<T>* &root);
  void rotateToRight(Node<T>* &root);
  void balanceFromLeft(Node<T>* &root);
  void balanceFromRight(Node<T>* &root);
  void insertIntoBst(Node<T>* &root, Node<T> *newNode, bool& isTaller);
};

template <typename T> Bst<T>::Bst() { root = nullptr; }

template <typename T> Bst<T>::~Bst() { Delete(root); }

/// Start of AVL STUFF


template <typename T>
void Bst<T>::rotateToLeft(Node<T>* &root) {
  if (root == nullptr) {
    std::cout << "Error in the tree" << std::endl;
  } else if (root->right == nullptr) {
    std::cout << "Error in the tree: No right subtree to rotate." << std::endl;
  } else {
    Node<T> *p = root->right;
    root->right = p->left;
    p->left = root;
    root = p;
  }
}

template <typename T>
void Bst<T>::rotateToRight(Node<T>* &root) {
  if (root == nullptr) {
    std::cout << "Error in the tree" << std::endl;
  } else if (root->left == nullptr) {
    std::cout << "Error in the tree: No left subtree to rotate." << std::endl;
  } else {
    Node<T> *p = root->left;
    root->left = p->right;
    p->right = root;
    root = p;
  }
}

template <typename T>
void Bst<T>::balanceFromLeft(Node<T>* &root) {
  Node<T> *p = root->left;
  Node<T> *w;
  switch (p->bfactor) {
    case -1:
      root->bfactor = 0;
      p->bfactor = 0;
      rotateToRight(root);
      break;
    case 1:
      w = p->right;
      switch (w->bfactor) {
        case -1:
          root->bfactor = 1;
          p->bfactor = 0;
          break;
        case 0:
          root->bfactor = 0;
          p->bfactor = 0;
          break;
        case 1:
          root->bfactor = 0;
          p->bfactor = -1;
          break;
      }
      w->bfactor = 0;
      rotateToLeft(p);
      root->left = p;
      rotateToRight(root);
      break;
    default:
      std::cout << "Error: Cannot balance from the left." << std::endl;
      break;
  }
}

template <typename T>
void Bst<T>::balanceFromRight(Node<T>* &root) {
  Node<T> *p = root->right;
  Node<T> *w;
  switch (p->bfactor) {
    case 1:
      root->bfactor = 0;
      p->bfactor = 0;
      rotateToLeft(root);
      break;
    case -1:
      w = p->left;
      switch (w->bfactor) {
        case -1:
          root->bfactor = 0;
          p->bfactor = 1;
          break;
        case 0:
          root->bfactor = 0;
          p->bfactor = 0;
          break;
        case 1:
          root->bfactor = -1;
          p->bfactor = 0;
          break;
      }
      w->bfactor = 0;
      rotateToRight(p);
      root->right = p;
      rotateToLeft(root);
      break;
    default:
      std::cout << "Error: Cannot balance from the right." << std::endl;
      break;
  }
}

template <typename T>
void Bst<T>::insertIntoBst(Node<T>* &root, Node<T> *newNode, bool& isTaller) {
  if (root == nullptr) {
    root = newNode;
    isTaller = true;
  } else if (root->info == newNode->info) {
    std::cout << "No duplicates are allowed." << std::endl;
  } else if (root->info > newNode->info) {
    insertIntoBst(root->left, newNode, isTaller);
    if (isTaller) {
      switch (root->bfactor) {
        case -1:
          balanceFromLeft(root);
          isTaller = false;
          break;
        case 0:
          root->bfactor = -1;
          isTaller = true;
          break;
        case 1:
          root->bfactor = 0;
          isTaller = false;
          break;
      }
    }
  } else {
    insertIntoBst(root->right, newNode, isTaller);
    if (isTaller) {
      switch (root->bfactor) {
        case -1:
          root->bfactor = 0;
          isTaller = false;
          break;
        case 0:
          root->bfactor = 1;
          isTaller = true;
          break;
        case 1:
          balanceFromRight(root);
          isTaller = false;
          break;
      }
    }
  }
}

template <typename T>
void Bst<T>::Insert(T newData) {
  bool isTaller = false;
  Node<T> *newNode = new Node<T>(newData);
  insertIntoBst(root, newNode, isTaller);
}


/// END OF AVL STUFF

/*template <typename T> void Bst<T>::Insert(T newData) {*/
/*  Node<T> *newNode = new Node<T>(newData);*/
/*  Node<T> *current;*/
/*  Node<T> *trailCurrent;*/
/*  if (root == nullptr) {*/
/*    root = newNode;*/
/*    return;*/
/*  } else {*/
/*    current = root;*/
/*  }*/
/*  while (current != nullptr) {*/
/*    trailCurrent = current;*/
/*    if (current->info == newData) {*/
/*      return;*/
/*    } else if (current->info > newData) {*/
/*      current = current->left;*/
/*    } else {*/
/*      current = current->right;*/
/*    }*/
/*  }*/
/*  if (trailCurrent->info > newData) {*/
/*    trailCurrent->left = newNode;*/
/*  } else {*/
/*    trailCurrent->right = newNode;*/
/*  }*/
/*}*/
template <typename T> void Bst<T>::Delete(Node<T> *&root) {
  if (root == nullptr) {
    return;
  }

  Delete(root->left);
  Delete(root->right);

  delete root;
  root = nullptr;
};

template <typename T> bool Bst<T>::Search(Node<T> *node, T target) const {
  if (node == nullptr) {
    return false;
  }
  if (node->info == target) {
    // equivalent to == when only < is defined
    return true;
  }
  if (target < node->info) {
    return Search(node->left, target);
  } else {
    return Search(node->right, target);
  }
}

template <typename T> Node<T> *Bst<T>::FindNode(Node<T> *node, T target) const {
  if (node == nullptr) {
    return nullptr;
  }
  if (node->info == target) {
    return node;
  }
  if (target < node->info) {
    return FindNode(node->left, target);
  } else {
    return FindNode(node->right, target);
  }
}

template <typename T> T &Bst<T>::Get(T target) const {
  Node<T> *node = FindNode(root, target);
  if (node == nullptr) {
    throw std::runtime_error("Target not found in the tree");
  }
  return node->info;
}

template <typename T>
void Bst<T>::inOrder(Node<T> *root, PN processNode) const {
  if (root == nullptr) {
    return;
  }
  inOrder(root->left, processNode);
  processNode(root->info);
  inOrder(root->right, processNode);
}



template <typename T> void Bst<T>::printInOrder(PN processNode) const {
  if (root == nullptr) {
    std::cout << "Tree is empty";
  } else {
    inOrder(root, processNode);
  }
}


template <typename T> void Bst<T>::DeleteTree() { Delete(root); }

template <typename T> bool Bst<T>::SearchTree(const T &target) const {
  if (Search(root, target)) {
    return true;
  } else {
    return false;
  }
}

#endif // BST_H
