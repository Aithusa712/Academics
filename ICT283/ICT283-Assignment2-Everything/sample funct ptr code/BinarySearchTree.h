// Binary Search Tree class
//Doxygen comments needed in the declaration

// Make sure BinarySearchTree is minimal and complete. 
// Code from Lab 9 can come here too.

template <class T>
struct nodeType  // answer why struct encapsulation is used - rationale
				 // there are other approaches, choose which one is the most
				 // appropriate and provide rationale
{
	// your write the code
};

Other approaches to the above are possible. It could be in the bst class private or a class nodeType with everything private, declaring class bst as a friend. But you need to defend your encapsulation type - answer why you took a particular approach and consequences (pros/cons) of the approach you have taken.



// This is the template class interface. Class implementation // must be provided after the interface. Do not mix or no 
// marks will be given.
template <class T>
class BinarySearchTree // answer why class encapsulation is used - rationale
{
public:

typedef void (*f1Typ)(T &); // you are not restricted to a single parameter. You 
							// decide on how many parameters and provide rationale
							// do you want the caller to have read/write access?
	
	// you write whatever else is needed and defend that. You already have some from Lab 9.
	// insert and search is needed.

	void inOrderTraversal(f1Typ f1 ) const;
	
	void preOrderTraversal() const; // parameter f1 in here too. left as an exercise
	void postOrderTraversal() const; // parameter f1 in here too. left as an exercise

private:
    
    
	nodeType<T> *root;

			// you write the rest

	void inOrder(f1Typ f1, nodeType<T> *p) const;
	
	// you write whatever else is needed and defend that.


};

// The template class implementation will be here, after the
// interface. Why are the class interface and implementation
// being separated? Review unit materials and readings from 
// earlier topics.

// You write the rest. You already have some from Lab 9.