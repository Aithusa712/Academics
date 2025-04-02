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

/**
 * @brief Node structure for a binary tree
 *
 * This structure represents a node in a binary tree.
 * It contains information about the node, pointers to left
 * and right children, and a balancing factor.
 *
 * @tparam T Type of the information stored in the node.
 */
template <typename T> struct Node {
  T info;            /**< Information stored in the node */
  Node *left;       /**< Pointer to the left child */
  Node *right;      /**< Pointer to the right child */
  int bfactor;      /**< Balancing factor of the node */

  /**
   * @brief Construct a new Node object
   *
   * Initializes a new node with the specified information,
   * and sets left and right children to nullptr and the
   * balancing factor to 1.
   *
   * @param newInfo The information to store in the node.
   */
  Node(const T& newInfo)
    : info(newInfo), left(nullptr), right(nullptr), bfactor(1) {

    }

};
/**
 * \class Bst
 * \brief Binary Search Tree.
 */
template <typename T> class Bst {

  /**
   * @brief Type definition for a function pointer that processes a node.
   *
   * This function pointer can be used to reference functions
   * that take a reference to a node of type T and return nothing.
   *
   * @tparam T The type of the node to be processed.
   */
  typedef void (*ProcessNode)(T &);

public:
  /**
   * @brief Constructs a Bst object.
   */
  Bst();

  /**
   * @brief Destroys the Bst object and frees resources.
   */
  ~Bst();

  /**
   * @brief Inserts new data into the Bst.
   * @param newData The data to insert.
   */
  void Insert(const T& newData);

  /**
   * @brief Deletes a node from the Bst.
   * @param root The root node from which to delete.
   */
  void Delete(Node<T> *&root);

  /**
   * @brief Searches for a target value in the Bst.
   * @param node The current node to search from.
   * @param target The value to search for.
   * @return true if found, false otherwise.
   */
  bool Search(Node<T> *node, const T& target) const;

  /**
   * @brief Traverses the tree in order and applies a function to each node.
   * @param root The root node to start traversal.
   * @param processNode The function to apply.
   */
  void inOrder(Node<T> *root, ProcessNode processNode) const;

  /**
   * @brief Traverses the tree in order and applies a function to each node.
   * @param processNode The function to apply.
   */
  void inOrder(ProcessNode processNode) const;

  /**
   * @brief Deletes the entire tree and frees resources.
   */
  void DeleteTree();

  /**
   * @brief Searches for a target value in the entire Bst.
   * @param target The value to search for.
   * @return true if found, false otherwise.
   */
  bool SearchTree(const T &target) const;

  /**
   * @brief Retrieves a reference to a target value in the Bst.
   * @param target The value to retrieve.
   * @return A reference to the value.
   */
  T &Get(const T& target) const;

  /**
   * @brief Finds the node containing the target value.
   * @param node The current node to search from.
   * @param target The value to search for.
   * @return Pointer to the found node. nullptr if not found.
   */
  Node<T> *FindNode(Node<T> *node, const T& target) const;

protected:
  Node<T> *root; /// holds the root node of the tree

  /**
   * @brief Inserts a node into the Bst.
   * @param newNode The node to insert.
   * @param root The current root node.
   */
  void Insert(Node<T> *newNode, Node<T> *root); // for non AVL Bst

  /**
   * @brief Rotates the subtree to the left.
   * @param root The root of the subtree to rotate.
   */
  void rotateToLeft(Node<T> *&root);

  /**
   * @brief Rotates the subtree to the right.
   * @param root The root of the subtree to rotate.
   */
  void rotateToRight(Node<T> *&root);

  /**
   * @brief Balances the subtree from the left.
   * @param root The root of the subtree to balance.
   */
  void balanceFromLeft(Node<T> *&root);

  /**
   * @brief Balances the subtree from the right.
   * @param root The root of the subtree to balance.
   */
  void balanceFromRight(Node<T> *&root);

  /**
   * @brief Inserts a node into the Bst and checks for height changes.
   * @param root The root of the subtree.
   * @param newNode The new node to insert.
   * @param isTaller Reference to track if the tree is taller after insertion.
   */
  void insertIntoBst(Node<T> *&root, Node<T> *newNode, bool &isTaller);
};

  template <typename T> Bst<T>::Bst() { root = nullptr; }

  template <typename T> Bst<T>::~Bst() { Delete(root); }

  /// Start of AVL STUFF

  template <typename T> void Bst<T>::rotateToLeft(Node<T> *&root) {
    if (root == nullptr || root->right == nullptr) {
      return;
    } else {
      Node<T> *p = root->right;
      root->right = p->left;
      p->left = root;
      root = p;
    }
  }

  template <typename T> void Bst<T>::rotateToRight(Node<T> *&root) {
    if (root == nullptr || root->left == nullptr) {
      return;
    } else {
      Node<T> *p = root->left;
      root->left = p->right;
      p->right = root;
      root = p;
    }
  }

  template <typename T> void Bst<T>::balanceFromLeft(Node<T> *&root) {
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
      break;
    }
  }

  template <typename T> void Bst<T>::balanceFromRight(Node<T> *&root) {
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
      break;
    }
  }

  template <typename T>
  void Bst<T>::insertIntoBst(Node<T> *&root, Node<T> *newNode, bool &isTaller) {
    if (root == nullptr) {
      root = newNode;
      isTaller = true;
    } else if (root->info == newNode->info) {
      return;
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

  template <typename T> void Bst<T>::Insert(const T& newData) {
    bool isTaller = false;
    Node<T> *newNode = new Node<T>(newData);
    insertIntoBst(root, newNode, isTaller);
  }

  /// END OF AVL STUFF

  /// START OF NON AVL INSERT

  /*template <typename T> void Bst<T>::Insert(T newData) {*/
  /*  Node<T> *newNode = new Node<T>(newData);*/
  /*  if (root == nullptr) {*/
  /*    root = newNode;*/
  /*  } else {*/
  /*    Insert(newNode, root);*/
  /*  }*/
  /*}*/
  /**/

  /*template <typename T> void Bst<T>::Insert(Node<T> *newNode, Node<T> *root)
   * {*/
  /*  if (newNode->info < root->info) {*/
  /*    if (root->left == nullptr) {*/
  /*      root->left = newNode;*/
  /*    } else {*/
  /*      Insert(newNode, root->left);*/
  /*    }*/
  /*  } else {*/
  /*    if (root->right == nullptr) {*/
  /*      root->right = newNode;*/
  /*    } else {*/
  /*      Insert(newNode, root->right);*/
  /*    }*/
  /*  }*/
  /*}*/

  /// END OF NON AVL INSERT

  template <typename T> void Bst<T>::Delete(Node<T> *&root) {
    if (root == nullptr) {
      return;
    }

    Delete(root->left);
    Delete(root->right);

    delete root;
    root = nullptr;
  };

  template <typename T> bool Bst<T>::Search(Node<T> *node, const T& target) const {
    if (node == nullptr) {
      return false;
    }
    if (node->info == target) {
      return true;
    }
    if (target < node->info) {
      return Search(node->left, target);
    } else {
      return Search(node->right, target);
    }
  }

  template <typename T>
  Node<T> *Bst<T>::FindNode(Node<T> *node, const T& target) const {
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

  template <typename T> T &Bst<T>::Get(const T& target) const {
    Node<T> *node = FindNode(root, target);
    if (node == nullptr) {
      throw node;
    }
    return node->info;
  }

  template <typename T>
  void Bst<T>::inOrder(Node<T> *root, ProcessNode processNode) const {
    if (root == nullptr) {
      return;
    }
    inOrder(root->left, processNode);
    processNode(root->info);
    inOrder(root->right, processNode);
  }

  template <typename T> void Bst<T>::inOrder(ProcessNode processNode) const {
    if (root == nullptr) {
      return;
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
