
## Java 
- a free object-oriented general purpose programming language 
- designed to be able to use easily with Internet.
- a popular choice for implementing O-O designs and for developing web-based applications.
- architecturally neutral - program can run on a variety of different type of machines.

#### Java Architecture
- Java's architecture arises out of four interrelated technologies:
	- Java programming language
	- Java Application Programming Interface (API)
	- Java class file format
	- Java virtual machine (JVM)
- A program in source files is compiled into java class files, and class files are run on a JVM
	- System resources are accessed by calling methods in the classes that implement the Java API.
	- Java API is a set of runtime libraries that give you standard way to access the system resource of a host computer.
	- JVM and API together form a platform for compiled Java programs called Java 2 Platform or the Java runtime system.
	- Compiled java program, in byte code, can run on any machine with Java Platform (JRE) is installed.
	![[Pasted image 20241121153357.png]]
## Objects
- Everything is an object.
- Program is a bunch of objects telling each other what to do by sending message
- Each object has its own memory made up of other objects. 
- Every object has a type
- The only other values that are values of a primitive built-in type is boolean, char, int, float, doable.
- Each variable in the program has a type, either class type or primitivize type 

##### Creation of Objects and Declaration of Variables
- To use a new object, it need to be created. This is done via the *new* keyword in the format 
```
	type var = new type(args);
```
	- var is a variable of the right type to reference the object
	- type is the (class) type of the new object
	- args is the possible empty list of values which determine which object of 
	that type gets created
- A constructor for that class is called with the supplied arguments to construct the object.
- When new is used:
	- space for the new object is allocated on the heap (area of memory)
	- the object is constructed there and the variable is given a reference to the object.
- Declaring variables can be done anywhere in the program before the variable is used. 
- Variables should include initialization such as:
	```
	float g = 9.8;
	String greeting = new String("hello");
	```

##### Destroying Objects
- When a variable goes out of scope the program lose all reference to a particular object.
- Java Runtime System will notice a variable that goes out of scope and a background process called *garbage collector* will release the memory for that object.

##### Doing things to objects
- Objects in a class have 
	- fields - name components of the object (also known as instance variables or data members)
	- methods - named function with type arguments, return type and coded effect on the fields/
- The actual values of the field may change during running the program they define the *state* of the object. 
	- state can be changed by:
		- direct assignment
			- var.field = value;
		- direct access
			- var2 = var.field;
		- calling a method
			- var2 = var.method(args);
	- Variables declared final cannot be changed
	- Values can also be assigned using shallow copy:
		- var2 = var1;

## Methods and Controls
- Control in the body is with if/if-else, switch, for, while, do-while etc.
- Parameters of primitive type are passed by value to the method

## Call by value / reference
![[Pasted image 20241121160353.png]]![[Pasted image 20241121160405.png]]

## Static members
- Members usually belong to objects of the class
- It is sometimes useful to have members which belong to the class as whole: class members and class methods.
- These are declared in the class with the *static* modifier
- If a data member is declared static then only one such value can exist at a time during the running of the program.
- They can be accessed by classname.field
- Static methods can also be defined by classname.methods(args) even if no object of that class exist

## Library Classes
- Java includes many ready-built classes
- They supply well-designed data structures, or help with input and output, networking, and GUI's
- Some library classes are used directly by the compiler.


## Java Example
![[Pasted image 20241121161447.png]]

## Arrays in Java
- a linear collection of objects of the same type.

## Object Oriented Design
- General principles behind OOSE(object-oriented analysis and design method) are:
	- use of abstraction, encapsulation and interfaces
	- re-use of exchangeable components
	- inheritance
	- polymorphism
	- designing for problem domains (vs specific problems).
-  UML (Unified Modelling Language)

## UML
- graphical representation scheme
- enables developers to model object-oriented systems 
- flexible and extendible


#### Single Class
![[Pasted image 20241121162044.png]]
#### Class Diagram
![[Pasted image 20241121162106.png]]

#### Cardinality (multiplicity) notation
![[Pasted image 20241121162140.png]]
#### Properties and Visibility
![[Pasted image 20241121162241.png]]

#### Aggregation and Composition
- Aggregation a special form of association. It represents a has-a or part-of relationship
- Aggregation is object that can exist independently outside of the class it is called in
- Composition is the stronger form of aggregation
- Composition cannot exist independently, if the object that they are in is destroyed they are also destroyed.

## OO Design Methods
- Basic steps in OOSE are:
	- Analysis - identify classes, relationships and expected dynamic behavior
	- Design - refine the results 
	- Implementation - implement the classes


## Finding Classes
- List all abstractions in the problem domain
- Determine  the data members and public methods.
- Find super and sub classes of a class
- go through scenarios by role playing as the user.
- Record the overall arrangement between classes on a class diagram (UML)
- Check, simplify, increment, iterate
