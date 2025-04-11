# Programming Concepts and UML Reference Guide

## UML Diagram Relationships

### Inheritance / Specialization
```
Inherited Class ----|>  Base Class
```

### Composition
```
Base Class -----<//> Composited Class
```

### Aggregation
```
Base Class ------< > Aggregated Class
```

### Additional UML Notes
- For template classes, add a dotted [T] in the upper right corner
- Attributes are almost always private
- Methods can be public or private

## Object-Oriented Design Principles

### Encapsulation
- Don't expose internal structures for modification
- Example: Nodes in a BST should not be returned directly
- When passing elements by reference, mark them as `const`

#### Protecting Class Members
```cpp
// Protecting Retrievals 
const Type& getAttribute();

// Protecting Mutations
void setAttribute(const Type& obj);
```

### Avoiding Friend Functions
Any code written using friends can be written without them by using public methods:

```cpp
// Using friend function
void friendFunction(Test& obj)
{
    obj.a = 1;
    obj.b = 2;
}

// Better approach with public methods
void unfriendFunction(Test& obj)
{
    obj.setA(1);
    obj.setB(2);
}
```

### Single Responsibility / Low Coupling
- Functions should not be aware of any more than they need to
  - E.g., Vector should not be aware of File I/O
  - E.g., Calculations should not be "locked" to a problem's data type

### No Inlining
- Avoid inline functions for better code organization

### Minimal and Complete Class Design

#### Completeness
- A class should have everything it needs to function in the general case
- Use the acronym CRUD - Create, Read, Update, Delete
- If random index access is possible, ensure operations work on any index
- Class must manage its own memory:
  * Constructor
  * Destructor
  * Copy Constructor
- The class must support all reasonable operators:
  * Comparison and Equality (makes insertion into other data structures possible)
  * Assignment (usually equivalent to copy constructor)
  * Subscript `[]` access operators (for data structures with random access)

#### Minimality
- Goes back to single responsibility - is your class doing more than it needs to?
- Maximize reusability by keeping classes focused

### When Not to Use Classes
- Utility functions can be standalone in .h/.cpp files
- Data-only structures can be simple structs:

```cpp
// Don't use a class like this:
class Point
{
private:
    int x;
    int y;

public:
    int getX();
    // etc.
};

// Instead, use a struct:
struct Point
{
    int x;
    int y;
};
```

### Class Encapsulation
Reuse existing classes by "hiding" their interface and providing your own:
- Useful to change function names, hide methods, implement custom error handling

## C++ Conventions

- Braces on the next line after the declaration, vertically aligned
- Classes and function names have first letter capitalized
- Attributes start with "m_" for member

```cpp
class Track
{
public:
    void GetName();
    void SetName(string name);
private:
    string m_title;
};
```

## Data Structures Performance and Implementation

### Array-Based Structures
- **Time Complexities**:
  - Random access: O(1)
  - Search: O(n)
  - Shifting elements after insertion/deletion: O(n)
- **Memory Operations**:
  - Allocation: Entire array at once
  - Deallocation: Entire array at once

### Linked List-Based Structures
- **Time Complexities**:
  - Traverse to index: O(n)
  - Search: O(n)
  - No shifting needed
- **Memory Operations**:
  - Allocation: Iteratively create nodes O(n)
  - Deallocation: Recursively delete nodes O(n)

### Tree-Based Structures
- **Time Complexities**:
  - No direct indexing
  - BST search: O(log n) average case
  - Finding predecessor/successor: O(log n) average case
- **Memory Operations**:
  - Allocation: Insert each node O(n log n) average case
  - Deallocation: Post-order traversal and delete O(n)

### Hash-Based Structures
- **Time Complexities**:
  - Compute hash: O(1)
  - Resolving collision: O(n) worst case
  - No shifting needed
- **Memory Operations**:
  - Allocation: Hash and probe O(n²) worst case
  - Deallocation: Free the underlying array

## Common Data Structures

### Vectors
- Flexible array that automatically grows when required
- Operations: Create, Read, Update, Delete

### Sets
- Follows the mathematical definition of a set
- Operations: Union, Intersection, Difference, Subset, Find

### Maps
- Associates a key to a value: `Map<KeyType, ValueType>`
- Typically implemented with HashTable or BST
- Operations: Create (Add), Read (Retrieve), Update, Delete

### Stacks
- Last in, First out (LIFO) structure
- Property: Reverses the input
- Operations: Push (Create), Pop (Read/Delete)
- Error conditions: Overflow (push when full), Underflow (pop when empty)

### Queues
- First in, First out (FIFO) structure
- Operations: Enqueue (Create), Dequeue (Read/Delete)
- Error conditions: Overflow (enqueue when full), Underflow (dequeue when empty)

## Recursion
- Functions that call themselves
- Must have:
  - Base case (termination condition)
  - Recursive case

## Trees

- Hierarchical series of nodes
- Each node has a parent and children
- Topmost node with no parent is the root

### Binary Search Tree (BST)
- Binary: Each node can have up to 2 children
- Search: Follows BST property (smaller elements left, larger elements right)
- Operations:
  - Create: Insert node
  - Read: Find specific value or traverse
  - Delete: Replace with predecessor/successor

### BST Traversal Orders
- **Preorder**: Good for allocating memory
- **Inorder**: Generates sorted list
- **Postorder**: Good for destructors

Note: If trees are not balanced, operations may degrade to O(n)
- AVL Trees are one way to maintain balance

## Algorithms

### Searching
- **Linear Search**
  - Visit every element in the list
  - Worst case: O(n) when target not found or at the end
- **Binary Search**
  - Precondition: Sorted list
  - Start in the middle and divide search space in half each time
  - Time complexity: O(log n)

### Merge Algorithm
- Combine two sorted lists into one sorted output in O(n) time
- Traverse each list from left to right

### Sorting

#### O(n²) Algorithms
- **Selection Sort**: Extract minimum item and move to front
- **Insertion Sort**: Create sorted sublist on left, insert each new item
- **Bubble Sort**: Swap adjacent items pairwise from left to right

#### O(n log n) Algorithms
- **Quicksort**: Recursively partition a list
- **Mergesort**: Recursively break down list, then merge using merge algorithm

### Hashing
- Used for mappings (key → value)
- Key is processed by hash function to produce an index
- Collision handling:
  - Probing
  - Separate chaining

## Graphs
- Consist of vertices connected by edges
- Edges can be directed or undirected
- Representations:
  - Adjacency Matrices
  - Adjacency Lists

### Graph Algorithms
- **Traversal**:
  - Breadth First Search (BFS)
  - Depth First Search (DFS)
- **Applications**:
  - Minimum Spanning Tree
  - Shortest Paths
  - Topological Sort
